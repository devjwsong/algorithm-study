#include <iostream>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// O(n): DFS.
class Solution1 {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int leftNum = countNodes(root->left);
        int rightNum = countNodes(root->right);

        return 1 + leftNum + rightNum;
    }
};


// O(logn * logn): Binary search
class Solution2 {
public:
    bool isExist(TreeNode* root, int idx, int height) {
        TreeNode* cur = root;
        int left = 0, right = pow(2, height-1)-1;
        for (int h=1; h<height; ++h) {
            int mid = (left + right) / 2;
            if (idx <= mid) {
                cur = cur->left;
                right = mid;
            } else {
                cur = cur->right;
                left = mid + 1;
            }
        }

        return cur != nullptr;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        TreeNode* cur = root;
        int height = 1;
        while(cur->left != nullptr) {  // O(logn)
            cur = cur->left;
            ++height;
        }
        if (height == 1) return 1;

        int left = 0, right = pow(2, height-1)-1;
        while(left + 1 < right) {  // O(logn)
            int mid = (left + right) / 2;
            int res = isExist(root, mid, height); // O(logn) 
            if (res) {
                left = mid;
            } else {
                right = mid;
            }
        }

        if (isExist(root, right, height)) {
            return pow(2, height-1) + right;
        } else {
            return pow(2, height-1) + left; 
        }
    }
};