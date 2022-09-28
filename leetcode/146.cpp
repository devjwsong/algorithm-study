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

        Node (int _key, int _value) {
            key = _key;
            value = _value;
            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<int, Node*> key2Node;
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int _capacity) {
        capacity = _capacity;
        head = nullptr;
        tail = nullptr;
    }

    void moveBack(Node* node) {
        if (node != tail) {
            if (node == head) {
                head = head->next;
                head->prev = nullptr;
                node->next = nullptr;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    
    int get(int key) {
        if (key2Node.find(key) == key2Node.end()) return -1;

        Node* node = key2Node[key];
        int value = node->value;

        moveBack(node);

        return value;
    }
    
    void put(int key, int value) {
        if (key2Node.find(key) != key2Node.end()) {
            key2Node[key]->value = value;
            moveBack(key2Node[key]);
            return;
        }
        
        if (key2Node.size() == capacity) {
            key2Node.erase(head->key);
            Node* nextHead = head->next;
            head->next = nullptr;
            if (nextHead) nextHead->prev = nullptr;
            head = nextHead;
            if (!head) tail = nullptr;
        }

        Node* node = new Node(key, value);
        key2Node[key] = node;
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
};