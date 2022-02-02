#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    int get_len(ListNode *head) {
        ListNode *cur = head;
        int len = 0;
        while(cur != nullptr) {
            ++len;
            cur = cur->next;
        }

        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = get_len(headA);
        int lenB = get_len(headB);
        int diff = abs(lenA - lenB);

        ListNode* longer = nullptr;
        ListNode* shorter = nullptr;
        int numIters = 0;
        if (lenA >= lenB) {
            longer = headA;
            shorter = headB;
            numIters = lenB;
        } else {
            longer = headB;
            shorter = headA;
            numIters = lenA;
        }

        for (int i=0; i<diff; ++i) {
            longer = longer->next;
        }

        for (int i=0; i<numIters; ++i) {
            if (longer == shorter) {
                return longer;
            }

            longer = longer->next;
            shorter = shorter->next;
        }

        return nullptr;
    }
};


int main() {

    return 0;
}