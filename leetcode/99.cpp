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
Time: O(n)
Space: O(1)
Inorder traverse produces the sorted result in ascending order.
So, the outliers are those which are not sorted.
The prev is the previous node visited, and first & second are the nodes which should be changed.
The first error is prev > cur, so those two should be swapped, therefore first = prev, second = root.
However, if another error is found later, than current second should be updated, since outliers are only two.
It is intuitive if we imagine what the sorted array looks like if there are only two elements which are not sorted.
*/
class Solution {
public:
    TreeNode* first;
    TreeNode* second;
    TreeNode* prev;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;
            }
            second = root;
        }
        prev = root;
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT32_MIN);
        inorder(root);

        swap(first->val, second->val);
    }
};