#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    bool answer = false;
    int cur = 0;
    
    void search(TreeNode* root, int targetSum) {
        cur += root->val;
        if (!root->left && !root->right) {
            if (cur == targetSum) answer = true;
        }
        
        if (root->left) search(root->left, targetSum);
        if (root->right) search(root->right, targetSum);
        
        cur -= root->val;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        
        search(root, targetSum);
        
        return answer;
    }
};