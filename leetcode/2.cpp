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
    ListNode* mergeNodes(ListNode* cur1, ListNode* cur2, int extra) {
        ListNode* node = new ListNode();
        if (!cur1 && !cur2) {
            if (extra > 0) {
                node->val = extra;
            } else {
                node = nullptr;
            }
            
            return node;
        }
        
        if (cur1) {
            node->val += cur1->val;
        }
        if (cur2) {
            node->val += cur2->val;
        }
        node->val += extra;
        
        if (node->val >= 10) {
            extra = node->val / 10;
            node->val %= 10;
        } else {
            extra = 0;
        }
        
        if (cur1 && cur2) {
            node->next = mergeNodes(cur1->next, cur2->next, extra);
        } else if (cur1 && !cur2) {
            node->next = mergeNodes(cur1->next, nullptr, extra);
        } else if (!cur1 && cur2) {
            node->next = mergeNodes(nullptr, cur2->next, extra);
        }
        
        return node;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return mergeNodes(l1, l2, 0);
    }
};