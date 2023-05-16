#include <iostream>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 1. With extra memory.
class Solution1 {
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


// 2. Without extra memory.
class Solution2 {
public:
    ListNode* add(ListNode* l1, ListNode* l2, int extra) {
        if (!l1 && !l2) {
            if (extra > 0) {
                ListNode* newNode = new ListNode(extra);
                return newNode;
            }
            return nullptr;
        }

        if (!l1) {
            l2->val += extra;
            int newExtra = l2->val / 10;
            l2->val -= (newExtra * 10);
            l2->next = add(nullptr, l2->next, newExtra);
            return l2;
        }

        if (!l2) {
            l1->val += extra;
            int newExtra = l1->val / 10;
            l1->val -= (newExtra * 10);
            l1->next = add(l1->next, nullptr, newExtra);
            return l1;
        }

        l1->val += (l2->val + extra);
        int newExtra = l1->val / 10;
        l1->val -= (newExtra * 10);
        l1->next = add(l1->next, l2->next, newExtra);
        return l1;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }
};