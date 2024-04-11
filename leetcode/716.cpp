#include <iostream>
#include <set>

using namespace std;


/*
Using a double linked list to form a task and ordered set to track the maximum value.
Note that to define the comparator for struct pointers, there should be another comparator struct.
Also, to use the set in decreasing order, make sure to return a larger one in operator().
*/
struct Node {
    int val;
    int seq_num;
    Node* next;
    Node* prev;
};

struct Comp {
    bool operator()(const Node* node1, const Node* node2) const {
        if (node1->val == node2->val) {
            return node1->seq_num > node2->seq_num;
        }

        return node1->val > node2->val;
    }
};

class MaxStack {
public:
    Node* head;
    Node* tail;
    set<Node*, Comp> st;
    int seq_num = 0;

    MaxStack() {
        head = nullptr;
        tail = nullptr;
    }
    
    void push(int x) {
        struct Node* newNode = new Node();
        newNode->val = x;
        newNode->seq_num = seq_num;
        ++seq_num;
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        st.insert(newNode);
    }
    
    int pop() {
        int res = tail->val;
        st.erase(tail);
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            struct Node* newTail = tail->prev;
            tail->prev = nullptr;
            newTail->next = nullptr;
            tail = newTail;
        }

        return res;
    }
    
    int top() {
        return tail->val;
    }
    
    int peekMax() {
        struct Node* target = *(st.begin());
        return target->val;
    }
    
    int popMax() {
        struct Node* target = *(st.begin());
        int res = target->val;
        st.erase(target);
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else if (target == head) {
            struct Node* newHead = head->next;
            newHead->prev = nullptr;
            head->next = nullptr;
            head = newHead;
        } else if (target == tail) {
            struct Node* newTail = tail->prev;
            newTail->next = nullptr;
            tail->prev = nullptr;
            tail = newTail;
        } else {
            target->prev->next = target->next;
            target->next->prev = target->prev;
        }

        return res;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */