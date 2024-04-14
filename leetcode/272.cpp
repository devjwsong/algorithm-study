#include<iostream>
#include<queue>

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
Priority Queue + Traverse.
No matter how we traverse the tree, we store the difference between the target and the current node into a min heap.
Time: O(VlogV). (V: # of nodes)
Space: O(V).
*/
class Solution {
public:
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    void traverse(TreeNode* cur, double target) {
        if (!cur) return;

        double diff = abs(target - cur->val);
        pq.push({diff, cur->val});

        traverse(cur->left, target);
        traverse(cur->right, target);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        traverse(root, target);

        vector<int> res;
        for (int i=0; i<k; ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};