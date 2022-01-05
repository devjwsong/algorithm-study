#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            vector<int> state;
            return state;
        }

        vector<int> curState = inorderTraversal(root->left);
        curState.push_back(root->val);
        vector<int> nextState = inorderTraversal(root->right);
        
        curState.insert(curState.end(), nextState.begin(), nextState.end());

        return curState;
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> s;
        TreeNode* cur = root;

        while(cur != nullptr || !s.empty()) {
            while(cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }

            cur = s.top();
            answer.push_back(cur->val);

            cur = cur->right;
        }

        return answer;
    }
};