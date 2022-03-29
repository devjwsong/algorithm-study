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


// Merge Sort.
class Solution1 {
public:
    ListNode* mergeLists(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                cur->next = left;
                left = left->next;
            } else {
                cur->next = right;
                right = right->next;
            }
            cur = cur->next;
        }

        if (left != nullptr) {
            cur->next = left;
        } else if (right != nullptr) {
            cur->next = right;
        }
        
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        ListNode* leftSorted = sortList(head);
        ListNode* rightSorted = sortList(slow);

        return mergeLists(leftSorted, rightSorted);
    }
};


// Merge Sort. (Slightly more efficient.)
class Solution2 {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        if (left->val <= right->val) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;

        return merge(sortList(head), sortList(slow));
    }
};


// Merge Sort. (Bottom-up: O(1) space complexity)
class Solution3 {
public:
    ListNode* move(ListNode* cur, int step) {
        for (int i=0; i<step && cur != nullptr; ++i) {
            cur = cur->next;
        }
        
        return cur;
    }

    ListNode* merge(ListNode* left, ListNode* prevTail, int size) {
        // Get last tail.
        ListNode* tail = move(left, 2 * size);

        ListNode* right = move(left, size);
        ListNode* temp = move(left, size-1);
        if (temp != nullptr) temp->next = nullptr;
        temp = move(right, size-1);
        if (temp != nullptr) temp->next = nullptr;

        if (right != nullptr && left->val > right->val) {
            swap(left, right);
        }

        ListNode* newHead = left;
        ListNode* newTail = left;
        left = left->next;
        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                newTail->next = left;
                left = left->next;
            } else {
                newTail->next = right;
                right = right->next;
            }
            newTail = newTail->next;
        }

        if (left != nullptr) {
            newTail->next = left;
        } else if (right != nullptr) {
            newTail->next = right;
        }

        while (newTail->next != nullptr) {
            newTail = newTail->next;
        }
        
        prevTail->next = newHead;
        prevTail = newTail;
        prevTail->next = tail;
        
        return prevTail;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        int len = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            ++len;
            cur = cur->next;
        }

        ListNode* dummy = new ListNode(0);
        ListNode* left = head;
        for (int size=1; size<=len; size*=2) {
            ListNode* prevTail = dummy;
            while(left != nullptr) {
                prevTail = merge(left, prevTail, size);
                left = prevTail->next;
            }
            left = dummy->next;
        }

        return dummy->next;
    }
};
