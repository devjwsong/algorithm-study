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
    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int pStart, int pEnd, int iStart, int iEnd) {
        if (pStart > pEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[pStart]);
        if (pStart == pEnd) return root;

        int loc = iStart;
        for (int i=iStart; i<=iEnd; ++i) {
            if (inorder[i] == preorder[pStart]) {
                loc = i;
                break;
            }
        }

        root->left = buildSubTree(preorder, inorder, pStart+1, pStart+loc-iStart, iStart, loc-1);
        root->right = buildSubTree(preorder, inorder, pStart+loc-iStart+1, pEnd, loc+1, iEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildSubTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
};
