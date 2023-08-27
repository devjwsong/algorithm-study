#include <iostream>
#include <vector>

using namespace std;


/*
Dynamic Programming + DFS.
The path is not safe if there is at least one loop in it.
So we set the visited check to see if the function already has visited the node.
If a node has been visited but dp has not been updated, it is now set to 0.
Now all visits to this node will be considered as not safe.
Time: O(N).
Space: O(N).
*/
class Solution {
public:
    vector<int> dp;
    vector<bool> visited;

    int search(vector<vector<int>>& graph, int idx) {
        if (visited[idx]) {
            if (dp[idx] == -1) dp[idx] = 0;
            return dp[idx];
        }
        visited[idx] = true;
        if (graph[idx].size() == 0) return dp[idx] = 1;

        for (int i=0; i<graph[idx].size(); ++i) {
            int next = graph[idx][i];
            int res = search(graph, next);
            if (res == 0) return dp[idx] = 0;
        }

        return dp[idx] = 1;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        dp.assign(n, -1);
        visited.assign(n, false);

        vector<int> answer;
        for (int idx=0; idx<n; ++idx) {
            if (search(graph, idx) == 1) answer.push_back(idx);
        }
        return answer;
    }
};
