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
    int dia = 0;

    int getDiameter(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }

        int leftDia = getDiameter(node->left);
        int rightDia = getDiameter(node->right);

        // Containing only one branch
        int temp1 = 1 + max(leftDia, rightDia);
        // Containing both + current node
        int temp2 = 1 + leftDia + rightDia;

        dia = max(dia, max(temp1, temp2));

        return temp1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getDiameter(root);

        return dia-1;
    }
};