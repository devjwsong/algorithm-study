#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
One-pass + vector solution.
Time: O(n)
Space: O(n)
*/ 
class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* cur = head;
        while (cur != nullptr) {
            nodes.push_back(cur);
            cur = cur->next;
        }

        int removeIdx = nodes.size() - n;
        if (removeIdx == 0) {
            head = head->next;
        } else if (removeIdx == (nodes.size()-1)) {
            nodes[removeIdx-1]->next = nullptr;
        } else {
            nodes[removeIdx-1]->next = nodes[removeIdx+1];
        }

        return head;
    }
};


/*
Two-pass + two pointers solutinon.
Time:  O(n)
Space: O(1)
This is another brilliant trick! Using two pointers to calculate the indices.
Assume that the size of the list is m.
First, move fast n times, then it will be located to (m-n)th from the back.
If m == n, then m-n=0(fast == NULL), so we should eliminate the head.
If m > n, then fast is not NULL.
Next, move slow and fast until fast reaches the final node.
Since the number of nodes between slow and fast is (n-1),
if fast is the 1st from the back, then slow is n+1.
So we should eliminate the next node of slow.
If n == 1, then the next node is fast(which is final node), so slow->next = NULL is enough.
If n > 2, slow->next = slow->next->next is acceptable since at least one node is between slow and the final node. 
*/
class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        for (int i=1; i<=n; ++i) {
            fast = fast->next;
        }
        if (fast == nullptr) return head->next;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        if (n == 1) {
            slow->next = nullptr;
        } else {
            slow->next = slow->next->next;
        }

        return head;
    }
};


/*
Two-pass + two pointers solution (which is more intuitive...)
Time: O(n)
Space: O(1)
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* cur = head;
        while (cur) {
            ++size;
            cur = cur->next;
        }
        if (n == size) return head->next;
        
        cur = head;
        ListNode* prev = nullptr;
        int count = 0;
        while (cur) {
            ++count;
            if (count == (size+1-n)) {
                prev->next = cur->next;
                cur = cur->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        
        return head;
    }
};