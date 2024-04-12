#include <iostream>
#include <unordered_map>

using namespace std;


/*
(Not perfect solution...)
Double Linked List + Hash map.
When a count is decreased, there is no way to get a new max or min values in this implementation.
Time: (Amortized) O(1).
Space: O(N).
*/
struct Node {
    string key;
    int count;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class AllOne {
public:
    unordered_map<string, Node*> keyMap;
    unordered_map<int, Node*> countMap;
    int max_count = -1e9;
    int min_count = 1e9;

    AllOne() {
        
    }

    void addNode(Node* node, int count) {
        if (countMap.find(count) == countMap.end()) {
            countMap[count] = node;
        } else {
            node->next = countMap[count];
            countMap[count]->prev = node;
            countMap[count] = node;
        }
    }

    void removeNode(Node* node, int count) {
        if (!node->prev) {
            Node* newHead = node->next;
            if (newHead) newHead->prev = nullptr;
            countMap[count] = newHead;
        } else {
            node->prev->next = node->next;
            if (node->next) node->next->prev = node->prev;
        }

        if (!countMap[count]) countMap.erase(count);
        node->next = nullptr;
        node->prev = nullptr;
    }
    
    void inc(string key) {
        if (keyMap.find(key) == keyMap.end()) {
            Node* node = new Node();
            node->key = key;
            node->count = 1;
            keyMap[key] = node;
            
            max_count = max(max_count, node->count);
            min_count = node->count;
            addNode(node, node->count);
        } else {
            Node* node = keyMap[key];
            ++node->count;
            removeNode(node, node->count-1);
            
            max_count = max(max_count, node->count);
            if (countMap.find(min_count) == countMap.end()) min_count = node->count;
            addNode(node, node->count);
        }
    }
    
    void dec(string key) {
        Node* node = keyMap[key];
        --node->count;
        removeNode(node, node->count+1);

        if (node->count == 0) {
            keyMap.erase(key);
        } else {
            addNode(node, node->count);
        }

        if (keyMap.size() == 0) {
            max_count = -1e9;
            min_count = 1e9;
        } else {
            if (max_count == node->count+1 && countMap.find(max_count) == countMap.end()) {
                if (keyMap.find(key) == keyMap.end()) {
                    while (countMap.find(max_count) == countMap.end()) {
                        --max_count;
                    }
                } else {
                    max_count = node->count;
                }
            }
            if (min_count == node->count+1) {
                if (keyMap.find(key) == keyMap.end()) {
                    while (countMap.find(min_count) == countMap.end()) {
                        ++min_count;
                    }
                } else {
                    min_count = node->count;
                }
            }
        }
    }
    
    string getMaxKey() {
        if (countMap.size() == 0) return "";
        return countMap[max_count]->key;
    }
    
    string getMinKey() {
        if (countMap.size() == 0) return "";
        return countMap[min_count]->key;
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