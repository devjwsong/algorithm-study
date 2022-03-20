#include <iostream>
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        if (root == nullptr) return answer;

        queue<TreeNode*> q;
        vector<int> levelVals;
        q.push(root);
        q.push(nullptr);

        while(!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();

            if (cur != nullptr) {
                levelVals.push_back(cur->val);
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            } else {
                answer.push_back(levelVals);
                levelVals.clear();
                if (!q.empty()) {
                    q.push(nullptr);
                }
            }
        }

        return answer;
    }
};