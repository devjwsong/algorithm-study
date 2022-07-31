#include <iostream>

using namespace std;


 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        if (list1 == nullptr && list2 == nullptr) {
            return nullptr;
        }
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode *cur1 = list1;
        ListNode *cur2 = list2;
        while (cur1 != nullptr && cur2 != nullptr) {
            ListNode* next = new ListNode();
            if (cur1->val <= cur2->val) {
                next->val = cur1->val;
                cur1 = cur1->next;
            } else {
                next->val = cur2->val;
                cur2 = cur2->next;
            }

            cur->next = next;
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
};
