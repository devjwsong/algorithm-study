#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


struct Node {
    unordered_map<char, Node*> mp;
    string s;
    int count;

    Node (string _s) {
        s = _s;
        count = 0;
    }
};


class Trie {
public:
    Node* root;
    vector<pair<int, string>> res;

    Trie() {
        root = new Node("");
    }

    void insert(string sent, int time) {
        Node* cur = root;
        int n = sent.size();
        string s = "";
        for (int i=0; i<n; ++i) {
            char c = sent[i];
            s += c;
            if (cur->mp.find(c) == cur->mp.end()) {
                Node* node = new Node(s);
                cur->mp[c] = node;
            }
            cur = cur->mp[c];
        }
        cur->count += time;
    }

    vector<pair<int, string>> find(string prefix) {
        Node* pre = root;
        int n = prefix.size();
        for (int i=0; i<n; ++i) {
            char c = prefix[i];
            if (pre->mp.find(c) == pre->mp.end()) return {};
            pre = pre->mp[c];
        }

        dfs(pre);
        return res;
    }

    void dfs(Node* cur) {
        if (cur->count > 0) {
            res.push_back({cur->count, cur->s});
        }

        for (auto iter=cur->mp.begin(); iter!=cur->mp.end(); ++iter) {
            dfs(iter->second);
        }
    }
};


class AutocompleteSystem {
public:
    Trie* trie;
    string prefix;

    struct compare {
        bool operator() (const pair<int, string>& p1, const pair<int, string>& p2) {
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie = new Trie();

        int n = sentences.size();
        for (int i=0; i<n; ++i) {
            trie->insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            trie->insert(prefix, 1);
            prefix = "";
            return {};
        }

        prefix += c;
        vector<pair<int, string>> res = trie->find(prefix);
        sort(res.begin(), res.end(), compare());
        
        vector<string> answer;
        int n = min((int) res.size(), 3);
        for (int i=0; i<n; ++i) {
            answer.push_back(res[i].second);
        }
        trie->res.clear();

        return answer;
    }
};
