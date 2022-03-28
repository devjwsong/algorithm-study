#include <iostream>
#include <unordered_map>

using namespace std;


class LRUCache {
public:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node (int key, int value) {
            this->key = key;
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<int, Node*> key2Node;
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }

    void moveBack(Node* cur) {
        if (cur->next == nullptr) return;

        Node* prev = cur->prev;
        Node* next = cur->next;
        if (prev == nullptr) { // Head.
            next->prev = nullptr;
            head = next;
        } else {
            prev->next = next;
            next->prev = prev;
        }

        tail->next = cur;
        cur->prev = tail;
        cur->next = nullptr;
        tail = cur;
    }

    void addNode(Node* cur) {
        if (head == nullptr || tail == nullptr) {
            head = cur;
            tail = cur;
        } else {
            tail->next = cur;
            cur->prev = tail;
            tail = cur;
        }
    }
    
    int get(int key) {
        if (key2Node.find(key) == key2Node.end()) return -1;

        Node* cur = key2Node[key];
        int value = cur->value;

        moveBack(cur);

        return value;
    }
    
    void put(int key, int value) {
        if (key2Node.find(key) != key2Node.end()) {  // If the key already exists.
            Node* cur = key2Node[key];
            cur->value = value;
            moveBack(cur);
        } else {
            if (key2Node.size() == capacity) {  // The cache is full.                
                int headKey = head->key;
                Node *newHead = head->next;
                if (newHead == nullptr) {
                    head = nullptr;
                    tail = nullptr;
                } else {
                    head->next = nullptr;
                    newHead->prev = nullptr;
                    head = newHead;
                }

                delete key2Node[headKey];
                key2Node.erase(headKey);
            }

            Node* node = new Node(key, value);
            key2Node[key] = node;
            addNode(node);
        }
    }
};