#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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
    vector<vector<int>> answer;

    void traverse(TreeNode* root, int level) {
        if (root == nullptr) return;

        if (answer.size() < level) answer.push_back(vector<int> {});
        answer[level-1].push_back(root->val);

        traverse(root->left, level+1);
        traverse(root->right, level+1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        traverse(root, 1);
        
        for (int i=0; i<answer.size(); ++i) {
            if (i % 2 == 1) {
                reverse(answer[i].begin(), answer[i].end());
            }
        }

        return answer;
    }
};
