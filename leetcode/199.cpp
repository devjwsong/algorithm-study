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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        vector<int> answer;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            ++level;
            
            for (int i=0; i<size; ++i) {
                TreeNode* cur = q.front();
                q.pop();
                
                if (answer.size() < level) {
                    answer.push_back(cur->val);
                }
                if (cur->right) q.push(cur->right);
                if (cur->left) q.push(cur->left);
            }
        }
        
        return answer;
    }
};