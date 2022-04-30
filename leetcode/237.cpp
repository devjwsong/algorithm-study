#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* cur = node;
        while(cur->next != nullptr) {
            cur->val = cur->next->val;
            if (cur->next->next == nullptr) {
                cur->next = nullptr;
                break;
            } else {
                cur = cur->next;
            }
        }
    }
};