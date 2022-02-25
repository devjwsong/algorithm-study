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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* cur = head;
        while (cur != nullptr) {
            nodes.push_back(cur);
            cur = cur->next;
        }

        int removeIdx = nodes.size() - n;
        if (removeIdx == 0) {
            head = head->next;
        } else if (removeIdx == (nodes.size()-1)) {
            nodes[removeIdx-1]->next = nullptr;
        } else {
            nodes[removeIdx-1]->next = nodes[removeIdx+1];
        }

        return head;
    }
};