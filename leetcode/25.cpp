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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;

        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* start = nullptr;
        ListNode* end = nullptr;
        ListNode* next = nullptr;

        int count = 0, numRevs = 0;;
        while (cur != nullptr) {
            ++count;
            if (count < k) {
                if (count == 1) start = cur;
                cur = cur->next;
            } else if (count == k) {
                end = cur;
                next = end->next;
                if (prev != nullptr) {
                    prev->next = end;
                }
                ListNode* c = start;
                ListNode* n = c->next;
                while (c != end && n != nullptr) {
                    ListNode* nn = n->next;
                    n->next = c;
                    c = n;
                    n = nn;
                }
                start->next = next;
                ++numRevs;
                if (numRevs == 1) {
                    head = end;
                }
                
                cur = next;
                prev = start;
                next = nullptr;
                start = nullptr;
                end = nullptr;
                count = 0;
            }
        }

        return head;
    }
};