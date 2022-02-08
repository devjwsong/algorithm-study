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
    ListNode* mergeNodes(ListNode* node1, ListNode* node2, int extra) {
        ListNode* node = new ListNode();

        if (node1 == nullptr && node2 == nullptr) {
            if (extra == 0) {
                return nullptr;
            } else {
                node->val += extra;
                return node;
            }
        }

        if (node1 != nullptr) {
            node->val += node1->val;
        }
        if (node2 != nullptr) {
            node->val += node2->val;
        }
        node->val += extra;

        if (node->val >= 10) {
            extra = node->val / 10;
            node->val %= 10;
        } else {
            extra = 0;
        }

        if (node1 != nullptr && node2 != nullptr) {
            node->next = mergeNodes(node1->next, node2->next, extra);
        } else if (node1 != nullptr) {
            node->next = mergeNodes(node1->next, nullptr, extra);
        } else if (node2 != nullptr) {
            node->next = mergeNodes(node2->next, nullptr, extra);
        }

        return node;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return mergeNodes(l1, l2, 0);
    }
};