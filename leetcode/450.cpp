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


/*
Actually quite intuitive...
Since this is the BST, so we don't have to traverse all the nodes, but just have to follow the key.
And if the current node is the key, there are 4 cases.
1. Leaf => just delete it.
2. Only with left: make the right subtree as cur.
3. Only with right: make the left subtree as cur.
4. Both with left & right: follow the procedure.
Find the alter. -> Change the value or cur into that of alter. -> Delete the alter.
*/
class Solution {
public:
    TreeNode* findAlter(TreeNode* root) {
        if (!root) return nullptr;
        
        if (!root->left) return root;
        
        return findAlter(root->left);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left && !root->right) {
                return nullptr;
            }
            
            if (!root->left) {
                return root->right;
            } else if (!root->right) {
                return root->left;
            }
            
            TreeNode* alter = findAlter(root->right);
            root->val = alter->val;
            root->right = deleteNode(root->right, alter->val);
        }
        
        return root;
    }
};