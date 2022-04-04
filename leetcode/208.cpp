#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    char val;
    unordered_map<char, Node*> dict;
    string data;
    Node(char c) : val(c) {}
};

class Trie {
public:
    Node* head;

    Trie() {
        head = new Node('@');
    }
    
    void insert(string word) {
        Node* cur = head;
        for (int i=0; i<word.size(); ++i) {
            char c = word[i];
            if (cur->dict.find(c) != cur->dict.end()) {
                cur = cur->dict[c];
            } else {
                Node* node = new Node(c);
                cur->dict[c] = node;
                cur = node;
            }
        }

        cur->data = word;
    }
    
    bool search(string word) {
        Node* cur = head;
        for (int i=0; i<word.size(); ++i) {
            char c = word[i];
            if (cur->dict.find(c) == cur->dict.end()) {
                return false;
            } else {
                cur = cur->dict[c];
            }
        }

        return cur->data == word;
    }
    
    bool startsWith(string prefix) {
        Node* cur = head;
        for (int i=0; i<prefix.size(); ++i) {
            char c = prefix[i];
            if (cur->dict.find(c) == cur->dict.end()) {
                return false;
            } else {
                cur = cur->dict[c];
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */