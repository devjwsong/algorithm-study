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
    TreeNode* makeBST(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) {
            return new TreeNode(nums[start]);
        }

        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        TreeNode* left = makeBST(nums, start, mid-1);
        TreeNode* right = makeBST(nums, mid+1, end);

        root->left = left;
        root->right = right;

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = makeBST(nums, 0, nums.size()-1);

        return root;
    }
};