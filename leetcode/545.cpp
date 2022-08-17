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


/*
Very tricky. First, we need to know the traverse strategy is different between left subtree and right subtree.
That's why we save the root first, and traverse differently.
*/
class Solution {
public:
    vector<int> answer;

    bool isLeaf(TreeNode* node) {
        return !node->left && !node->right;
    }

    /*
    Pre-order traverse.
    The boundary flag indicates whether the current node should be included or not.
    The left traverse first keeps going with the flag, so if the parent node is not the boundary, 
    its children are not also the boundaries unless they are leaves.
    However, if the root is boundary but doesn't have the left child, the right child becomes the boundary instead.
    */
    void traverseLeft(TreeNode* root, bool boundary) {
        if (!root) return;
        if (boundary || isLeaf(root)) answer.push_back(root->val);

        traverseLeft(root->left, boundary);

        if (!root->left) {
            traverseLeft(root->right, boundary);
        } else {
            traverseLeft(root->right, false);
        }
    }

    /*
    Post-order traverse.
    Here, we need to check the left first since we count the left boundary in this question.
    Then traverseRight occurs, and finally record the node.
    */
    void traverseRight(TreeNode* root, bool boundary) {
        if (!root) return;
        if (!root->right) {
            traverseRight(root->left, boundary);
        } else {
            traverseRight(root->left, false);
        }
        
        traverseRight(root->right, boundary);

        if (boundary || isLeaf(root)) answer.push_back(root->val);
    }

    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        answer.push_back(root->val);

        traverseLeft(root->left, true);
        traverseRight(root->right, true);

        return answer;
    }
};