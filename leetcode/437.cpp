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
    int answer = 0;

    void search(TreeNode* root, int targetSum, vector<int>& sums) {
        if (!root) return;

        sums.push_back(root->val);
        long long temp = 0;
        for (int i=sums.size()-1; i>=0; --i) {
            temp += sums[i];
            if (temp == targetSum) ++answer;
        }
        search(root->left, targetSum, sums);
        search(root->right, targetSum, sums);
        sums.pop_back();
    }

    int pathSum(TreeNode* root, int targetSum) {
        vector<int> sums;
        search(root, targetSum, sums);

        return answer;
    }
};