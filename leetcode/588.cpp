#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;


struct Node {
    string name;
    unordered_map<string, Node*> child2Node;
    string content;
    bool isFile;

    Node (string _name, bool _isFile) {
        name = _name;
        isFile = _isFile;
    }
};


class FileSystem {
public:
    Node* root;

    FileSystem() {
        root = new Node("", false);
    }
    
    vector<string> split(string path) {
        vector<string> res;
        int n = path.size();
        string cur;
        for (int i=0; i<n; ++i) {
            if (path[i] == '/') {
                if (cur.size() > 0) res.push_back(cur);
                cur = "";
            } else {
                cur += path[i];
            }
        }
        if (cur.size() > 0) res.push_back(cur);

        return res;
    }

    vector<string> ls(string path) {
        vector<string> names = split(path);
        if (names.size() == 0) {
            vector<string> res;
            for (auto iter=root->child2Node.begin(); iter!=root->child2Node.end(); ++iter) {
                res.push_back(iter->first);
            }
            sort(res.begin(), res.end());
            return res;
        }
        
        Node* cur = root;
        for (int i=0; i<names.size(); ++i) {
            cur = cur->child2Node[names[i]];
        }

        if (cur->isFile) {
            return {cur->name};
        }
        vector<string> res;
        for (auto iter=cur->child2Node.begin(); iter!=cur->child2Node.end(); ++iter) {
            res.push_back(iter->first);
        }
        sort(res.begin(), res.end());

        return res;
    }

    pair<Node*, int> findStartingPoint(vector<string> names) {
        Node* cur = root;
        int start = names.size();
        for (int i=0; i<names.size(); ++i) {
            if (cur->child2Node.find(names[i]) == cur->child2Node.end()) {
                start = i;
                break;
            } else {
                cur = cur->child2Node[names[i]];
            }
        }
        
        return {cur, start};
    }
    
    void mkdir(string path) {
        vector<string> names = split(path);
        if (names.size() == 0) return;

        pair<Node*, int> point = findStartingPoint(names);
        Node* cur = point.first;
        int start = point.second;
        if (start == names.size()) return;

        for (int i=start; i<names.size(); ++i) {
            Node* node = new Node(names[i], false);
            cur->child2Node[names[i]] = node;
            cur = cur->child2Node[names[i]];
        }
    }
    
    void addContentToFile(string filePath, string content) {
        vector<string> names = split(filePath);
        if (names.size() == 0) return;

        pair<Node*, int> point = findStartingPoint(names);
        Node* cur = point.first;
        int start = point.second;
        if (start == names.size()) {
            cur->content += content;
            return;
        }

        for (int i=start; i<names.size(); ++i) {
            Node* node = new Node(names[i], false);
            if (i == names.size()-1) node->isFile = true;
            cur->child2Node[names[i]] = node;
            cur = cur->child2Node[names[i]];
        }

        cur->content = content;
    }
    
    string readContentFromFile(string filePath) {
        vector<string> names = split(filePath);
        
        Node* cur = root;
        for (int i=0; i<names.size(); ++i) {
            cur = cur->child2Node[names[i]];
        }

        return cur->content;
    }
};