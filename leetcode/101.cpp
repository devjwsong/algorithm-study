#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Recursively
class Solution1 {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (left && !right) return false;
        if (!left && right) return false;
        if (left->val != right->val) return false;
        
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};


// Iteratively
class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        
        while(!q.empty()) {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();

            if (left == nullptr && right == nullptr) {
                continue;
            }

            if (left == nullptr || right == nullptr) {
                return false;
            }

            if (left->val != right->val) {
                return false;
            }

            q.push(left->left);
            q.push(right->right);
            q.push(left->right);
            q.push(right->left);
        }

        return true;
    }
};
