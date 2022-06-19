#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


/*
Divide & Conquer
Time: O(NlogK)
Space: O(logK)
*/
class Solution1 {
public:
    ListNode* merge(vector<ListNode*>& lists, int i, int j) {
        if (i > j) return nullptr;
        if (i == j) return lists[i];

        ListNode* leftMerged = merge(lists, i, (i+j)/2);
        ListNode* rightMerged = merge(lists, (i+j)/2+1, j);

        ListNode* cur1 = leftMerged;
        ListNode* cur2 = rightMerged;

        ListNode* head = new ListNode(-10001);
        ListNode* cur = head;
        while(cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val < cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
            } else {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }

        if (cur1 != nullptr) {
            cur->next = cur1;
        }
        if (cur2 != nullptr) {
            cur->next = cur2;
        }

        return head->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge(lists, 0, lists.size()-1);
    }
};


/*
Min heap (Priority Queue)
Time: O(NlogK)
Space: O(logK)
*/
class Solution2 {
public:
    struct Compare {
        bool operator()(ListNode* node1, ListNode* node2) {
            return node1->val > node2->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        int k = lists.size();
        for (int i=0; i<k; ++i) {
            if (lists[i] != nullptr) {
                pq.push(lists[i]);
            }
        }

        ListNode* head = new ListNode(-10001);
        ListNode* cur = head;
        while (!pq.empty()) {
            ListNode* curTop = pq.top();
            pq.pop();

            cur->next = curTop;
            cur = cur->next;
            
            curTop = curTop->next;
            if (curTop != nullptr) {
                pq.push(curTop);
            }
        }

        return head->next;
    }
};