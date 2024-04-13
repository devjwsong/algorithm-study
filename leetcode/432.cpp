#include <iostream>
#include <unordered_set>
#include <unordered_map>

using namespace std;


/*
Double Linked List + Hash map.
The idea is to keep the head as min count and tail as max count.
Also, each node contain the keys, so that they can be retrieved anytime.
Time: O(1).
Space: O(N).
*/
class AllOne {
public:
    struct Node {
        int count;
        unordered_set<string> keySet;
        Node* next;
        Node* prev;

        Node(int _count, string& key) {
            count = _count;
            keySet.insert(key);
            next = nullptr;
            prev = nullptr;
        }
    };

    Node* head;  // Min count.
    Node* tail;  // Max count.
    unordered_map<string, Node*> mp;

    AllOne() {
        head = nullptr;
        tail = nullptr;
    }
    
    void inc(string key) {
        if (!head) {  // No data.
            Node* node = new Node(1, key);
            head = node;
            tail = node;
            mp[key] = node;
            return;
        }

        if (mp.find(key) == mp.end()) {  // There is some keys, but a new key has been added.
            if (head->count == 1) {  // If the head's count is 1, putting the key in head.
                head->keySet.insert(key);
                mp[key] = head;

            } else {  // If the head's count is not 1, this becomes a new head.
                Node* node = new Node(1, key);
                head->prev = node;
                node->next = head;
                head = node;
                mp[key] = node;
            }
        } else {  // The key already exists.
            Node* node = mp[key];
            if (node == tail) {  // If this key is already maximum...
                tail->keySet.erase(key);
                Node* newNode = new Node(tail->count+1, key);
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
                mp[key] = tail;

            } else {  // If the key is not a maximum...
                if (node->next->count == node->count + 1) {  // Moving to the next.
                    node->keySet.erase(key);
                    node->next->keySet.insert(key);
                    mp[key] = node->next;
                } else {  // Just increasing the value.
                    node->keySet.erase(key);
                    Node* newNode = new Node(node->count+1, key);
                    node->next->prev = newNode;
                    newNode->next = node->next;
                    newNode->prev = node;
                    node->next = newNode;
                    mp[key] = newNode;
                }

            }

            // If the original node becomes empty...
            if (node->keySet.empty()) {
                if (node == head && node == tail) {
                    head = nullptr;
                    tail = nullptr;
                } else if (node == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (node == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                }
            }
        }
    }
    
    void dec(string key) {
        Node* node = mp[key];
        if (node->count > 1) {  // If the count is larger than 1.
            if (node == head) {  // If the node is head.
                head->keySet.erase(key);
                Node* newNode = new Node(head->count-1, key);
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
                mp[key] = head;
            } else {  // If the node is not the head.
                if (node->prev->count == node->count-1) {  // Moving to the previous node.
                    node->keySet.erase(key);
                    node->prev->keySet.insert(key);
                    mp[key] = node->prev;
                } else {  // Adding a new node.
                    node->keySet.erase(key);
                    Node* newNode = new Node(node->count-1, key);
                    node->prev->next = newNode;
                    newNode->prev = node->prev;
                    newNode->next = node;
                    node->prev = newNode;
                    mp[key] = newNode;
                }
            }
        } else {  // If the count is 1.
            node->keySet.erase(key);
            mp.erase(key);
        }

        // If the original node becomes empty...
        if (node->keySet.empty()) {
            if (node == head && node == tail) {
                head = nullptr;
                tail = nullptr;
            } else if (node == tail) {
                tail = node->prev;
                tail->next = nullptr;
            } else if (node == head) {
                head = node->next;
                head->prev = nullptr;
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
        }
    }
    
    string getMaxKey() {
        if (mp.empty()) return "";
        return *(tail->keySet.begin());
    }
    
    string getMinKey() {
        if (mp.empty()) return "";
        return *(head->keySet.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */