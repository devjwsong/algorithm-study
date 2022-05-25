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
    ListNode* oddEvenList(ListNode* head) {
        int idx = 1;
        ListNode* odd = new ListNode(INT32_MIN);
        ListNode* even = new ListNode(INT32_MIN);

        ListNode* cur = head;
        ListNode* oddCur = odd;
        ListNode* evenCur = even;
        while (cur != nullptr) {
            if (idx % 2 == 1) {
                oddCur->next = cur;
                oddCur = oddCur->next;
            } else {
                evenCur->next = cur;
                evenCur = evenCur->next;
            }
            ++idx;
            cur = cur->next;
        }
        oddCur->next = nullptr;
        evenCur->next = nullptr;
        
        oddCur->next = even->next;
        
        return odd->next;
    }
};
