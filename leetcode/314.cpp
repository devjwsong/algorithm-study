#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <climits>

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
DFS + BFS.
DFS is used for checking the minimum/maximum level in the tree so that we can initialize the vector.
Then BFS fills the nodes for each level.
Time: O(N).
Space: O(N).
*/
class Solution1 {
public:
    vector<vector<int>> answer;
    int left = INT_MAX;
    int right = INT_MIN;

    void dfs(TreeNode* node, int level) {
        if (!node) return;
        left = min(left, level);
        right = max(right, level);

        dfs(node->left, level-1);
        dfs(node->right, level+1);
    }

    void bfs(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, -left});

        while (!q.empty()) {
            pair<TreeNode*, int> cur = q.front();
            q.pop();

            answer[cur.second].push_back(cur.first->val);

            if (cur.first->left) q.push({cur.first->left, cur.second-1});
            if (cur.first->right) q.push({cur.first->right, cur.second+1});
        }
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return answer;
        
        dfs(root, 0);
        int numLevels = right - left + 1;
        answer.assign(numLevels, vector<int> ());

        bfs(root);

        return answer;
    }
};


/*
Map + BFS.
Using the map, we can keep the sorted order of the levels.
BFS updates the vector for each level.
Time: O(NlogN).
Space: O(N).
*/
class Solution2 {
public:
    vector<vector<int>> answer;
    map<int, vector<int>> mp;

    void bfs(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            pair<TreeNode*, int> cur = q.front();
            q.pop();

            mp[cur.second].push_back(cur.first->val);

            if (cur.first->left) q.push({cur.first->left, cur.second-1});
            if (cur.first->right) q.push({cur.first->right, cur.second+1});
        }
    }

    vector<vector<int>> verticalOrder(TreeNode* root) {
        if (!root) return answer;
        bfs(root);

        for (map<int, vector<int>>::iterator iter=mp.begin(); iter != mp.end(); ++iter) {
            answer.push_back(iter->second);
        }

        return answer;
    }
};
