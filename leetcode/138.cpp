#include <iostream>
#include <unordered_map>

using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;

        unordered_map<Node*, Node*> mapper;

        Node* cur = head;
        Node* newHead = new Node(head->val);
        Node* newCur = newHead;

        while(cur != nullptr) {
            mapper[cur] = newCur;
            newCur->random = cur->random;

            Node* next = cur->next;
            if (next == nullptr) break;

            Node* newNext = new Node(next->val);
            newCur->next = newNext;

            cur = next;
            newCur = newNext;
        }

        cur = newHead;
        while(cur != nullptr) {
            if (cur->random != nullptr) {
                cur->random = mapper[cur->random];
            }
            cur = cur->next;
        }

        return newHead;
    }
};