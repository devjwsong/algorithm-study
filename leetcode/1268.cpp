#include <iostream>
#include <vector>

using namespace std;


struct Node {
    char c;
    string s;
    bool isExist;
    vector<Node*> children;

    Node(char _c) {
        c = _c;
        isExist = false;
        children.assign(26, nullptr);
    }
};

class Solution {
public:
    Node* root = new Node('@');
    vector<vector<string>> answer;
    vector<string> suggestions;

    void add(string word) {
        Node* cur = root;
        int n = word.size();
        for (int i=0; i<n; ++i) {
            char c = word[i];

            if (!cur->children[c-'a']) {
                Node* node = new Node(c);
                node->s = cur->s + c;
                cur->children[c-'a'] = node;
            }
            cur = cur->children[c-'a'];
        }

        cur->isExist = true;
    }

    void search(Node* cur, string& prefix, int idx) {
        if (idx < prefix.size()) {
            char c = prefix[idx];
            if (!cur->children[c-'a']) return;
            search(cur->children[c-'a'], prefix, idx+1);
        } else {
            if (cur->isExist) {
                if (suggestions.size() < 3) suggestions.push_back(cur->s);
            }

            for (int i=0; i<26; ++i) {
                if (cur->children[i]) {
                    search(cur->children[i], prefix, idx+1);
                }
            }
        }
    }

    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for (int i=0; i<products.size(); ++i) {
            add(products[i]);
        }

        int n = searchWord.size();
        for (int i=0; i<n; ++i) {
            suggestions = {};
            string prefix = searchWord.substr(0, i+1);
            search(root, prefix, 0);
            answer.push_back(suggestions);
        }

        return answer;
    }
};


int main() {

    int n;
    cin>>n;
    getchar();

    vector<string> products;
    for (int i=0; i<n; ++i) {
        string product;
        cin>>product;
        products.push_back(product);
    }

    getchar();
    string searchWord;
    cin>>searchWord;

    Solution* sol = new Solution();
    vector<vector<string>> answer = sol->suggestedProducts(products, searchWord);
    for (int i=0; i<answer.size(); ++i) {
        for (int j=0; j<answer[i].size(); ++j) {
            cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }
}