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
    int answer = 0;
    
    /*
    This function always return the diameter which ends with the root.
    So there is no meaning of considering the other cases.
    */
    int getDiameter(TreeNode* root) {
        if (!root) return 0;

        // Each result is larger than the original diameter by 1.
        int leftRes = getDiameter(root->left);
        int rightRes = getDiameter(root->right);

        // Containing only one branch.
        int temp1 = 1 + max(leftRes, rightRes);
        /*
        Containing both + current node.
        The reason why only 1 is added, not 2, is because we want to keep the answer
        larger than the original answer only by 1.
        */ 
        int temp2 = 1 + leftRes + rightRes;

        answer = max(answer, max(temp1, temp2));

        return temp1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        getDiameter(root);

        return answer-1;
    }
};