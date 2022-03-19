#include <iostream>
#include <vector>

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
    vector<int> getTreeInfo(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return vector<int> {1, root->val, root->val};

        } else if (root->right == nullptr) {
            vector<int> leftInfo = getTreeInfo(root->left);
            if (leftInfo[0] == 1 && leftInfo[2] < root->val) {
                return vector<int> {1, leftInfo[1], root->val};
            } else {
                return vector<int> {0, root->val, root->val};
            }

        } else if (root->left == nullptr) {
            vector<int> rightInfo = getTreeInfo(root->right);
            if (rightInfo[0] == 1 && rightInfo[1] > root->val) {
                return vector<int> {1, root->val, rightInfo[2]};
            } else {
                return vector<int> {0, root->val, root->val};
            }

        } else {
            vector<int> leftInfo = getTreeInfo(root->left);
            vector<int> rightInfo = getTreeInfo(root->right);
            if (leftInfo[0] && rightInfo[0] && root->val > leftInfo[2] && root->val < rightInfo[1]) {
                return vector<int> {1, leftInfo[1], rightInfo[2]};
            } else {
                return vector<int> {0, root->val, root->val};
            }
        }
    }

    bool isValidBST(TreeNode* root) {
        vector<int> treeInfo = getTreeInfo(root);
        if (treeInfo[0] == 1) {
            return true;
        } else {
            return false;
        }
    }
};