#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// Post-order + stack.
class Codec1 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string left = serialize(root->left);
        string leftLen = to_string(left.size());
        string right = serialize(root->right);
        string rightLen = to_string(right.size());
        string cur = to_string(root->val);
        
        return "(" + leftLen + "#" + left + "|" + cur + "|" + rightLen + "#" + right + ")";
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return nullptr;
        if (data[0] != '(') {
            TreeNode* node = new TreeNode(stoi(data));
            return node;
        }
        
        int i=1, n = data.size();
        string s;
        int sepCount = 0;
        TreeNode* left = nullptr;
        TreeNode* cur = nullptr;
        TreeNode* right = nullptr;
        while (i < n-1) {
            if (data[i] == '|') {
                if (sepCount == 0) left = deserialize(s);
                if (sepCount == 1) cur = deserialize(s);
                ++sepCount;
                s = "";
                ++i;
            } else if (data[i] == '#') {
                int len = stoi(s);
                s = data.substr(i+1, len);
                i = i + 1 + len;
            } else {
                s += data[i];
                ++i;
            }
        }
        right = deserialize(s);
        
        if (cur) {
            cur->left = left;
            cur->right = right;
        }
        
        return cur;
    }
};


// Pre-order: A little more simple and fast.
class Codec2 {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) {
            string res = "";
            res += to_string(1001);
            res += " ";
            return res;
        }
        
        string res = to_string(root->val);
        res += " ";
        res += serialize(root->left);
        res += serialize(root->right);
        
        return res;
    }

    // Decodes your encoded data to tree.
    int idx = 0;
    TreeNode* deserialize(string data) {
        return func(data);
    }
    
    TreeNode* func(string& data) {
        string s = "";
        
        while (idx < data.size() && data[idx] != ' ') {
            s += data[idx];
            ++idx;
        }
        ++idx;
        int val = stoi(s);
        if (val == 1001) return nullptr;
        
        TreeNode* root = new TreeNode(val);
        root->left = func(data);
        root->right = func(data);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));