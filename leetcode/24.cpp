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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        if (cur == nullptr || cur->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* next = cur->next;
        while(cur != nullptr && next != nullptr) {
            if (cur == head) {
                head = next;
            }

            if (prev != nullptr) {
                prev->next = next;
            }

            cur->next = next->next;
            next->next = cur;
            prev = cur;
            cur = cur->next;
            if (cur == nullptr || cur->next == nullptr) {
                break;
            } else {
                next = cur->next;
            }
        }

        return head;
    }
};