#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Naive search
class Solution1 {
public:
    bool find(TreeNode* cur, int val) {
        if (cur == nullptr) return false;
        if (cur->val == val) return true;

        return find(cur->left, val) || find(cur->right, val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while(cur != nullptr) {
            if (cur->val == p->val || cur->val == q->val) return cur;

            bool leftP = find(cur->left, p->val);
            bool rightP = find(cur->right, p->val);
            bool leftQ = find(cur->left, q->val);
            bool rightQ = find(cur->right, q->val);

            if ((leftP && rightQ) || (leftQ && rightP)) {
                return cur;
            } else {
                if (leftP && leftQ) {
                    cur = cur->left;
                } else if (rightQ && rightQ) {
                    cur = cur->right;
                }
            }
        }

        return cur;
    }
};

// More efficient
class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root->val == p->val || root->val == q->val) return root;

        TreeNode* leftRes = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightRes = lowestCommonAncestor(root->right, p, q);

        if (leftRes == nullptr) return rightRes;
        if (rightRes == nullptr) return leftRes;

        return root;
    }
};