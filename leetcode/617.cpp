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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        }

        TreeNode* node = new TreeNode();

        if (root1 != nullptr) {
            node->val += root1->val;
        }

        if (root2 != nullptr) {
            node->val += root2->val;
        }

        if (root1 != nullptr && root2 != nullptr) {
            node->left = mergeTrees(root1->left, root2->left);
            node->right = mergeTrees(root1->right, root2->right);
        } else if (root1 != nullptr) {
            node->left = root1->left;
            node->right = root1->right;
        } else if (root2 != nullptr) {
            node->left = root2->left;
            node->right = root2->right;
        }

        return node;
    }
};