#include <iostream>
#include <utility>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iteratively
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* newNode = nullptr;
        while(cur != nullptr) {
            if (newNode == nullptr) {
                newNode = new ListNode(cur->val);
            }
            if (cur->next != nullptr) {
                ListNode *nextNode = new ListNode(cur->next->val);
                nextNode->next = newNode;
                newNode = nextNode;
            }
            cur = cur->next;
        }

        return newNode;
    }
};


// Recursively
class Solution2 {
public:
    pair<ListNode*, ListNode*> iterList(ListNode* head) {
        if (head->next == nullptr) {
            return pair<ListNode*, ListNode*> (head, head);
        }

        ListNode* node = new ListNode(head->val);
        pair<ListNode*, ListNode*> traveled = iterList(head->next);
        ListNode* recent = traveled.first;
        ListNode* last = traveled.second;
        recent->next = node;

        return pair<ListNode*, ListNode*> (node, last);
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        return iterList(head).second;
    }
};


// Very very simple
class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode* cur = head;
        ListNode* next = cur->next;
        while (cur && next) {
            ListNode* nn = next->next;
            next->next = cur;
            cur = next;
            next = nn;
        }
        head->next = nullptr;
        
        return cur;
    }
};