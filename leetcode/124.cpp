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
Actually very simple, though it seems there are many possible cases.
Obviously, the base case is when the root is null, which is the answer 0.
And we have left/right result each from a pair of recursive calls.
We update the global variable answer using all possible values.
1. Connecting left result and right result with the root.
2. Choosing only either left/right option and connecting with the root.
3. Not including left/right results and choosing only the root.
And the return value should be 2 or 3, since 1 cannot connect further path with other nodes in upper levels.
Additionally, the final return value is not necessarily same as the answer.
Since these recursive calls calculate the maximum values in greedy method, the optimal answer can be corrupted.
However, the global variable answer is updated according to all possible values eventually, this can be seen as dynamic programming.
*/
class Solution {
public:
    int answer = INT32_MIN;
    int findPath(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int leftRes = findPath(root->left) + root->val;
        int rightRes = findPath(root->right) + root->val;
        
        answer = max(answer, leftRes + rightRes - root->val);
        answer = max(answer, max(leftRes, rightRes));
        answer = max(answer, root->val);
        
        return max(root->val, max(leftRes, rightRes));
    }

    int maxPathSum(TreeNode* root) {
        int res = findPath(root);
        return answer;
    }
};