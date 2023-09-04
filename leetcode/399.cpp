#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


/*
Hash map + BFS.
We can represent the relation between each pair into a weighted edge between two nodes.
Then we search the answer for c/d by traversing from c and d.
Time: O(Q*(V+E)). => Note that we can optimize this into O(V+E) by saving the calculation results from previous queries.
while it would take more space!!
Space: O(V+E).
*/
class Solution1 {
public:
    unordered_map<string, vector<pair<double, string>>> graph;

    double bfs(string start, string target) {
        if (graph.find(start) == graph.end() || graph.find(target) == graph.end()) return -1.0;

        queue<pair<double, string>> q;
        unordered_set<string> visited;
        q.push({1.0, start});
        visited.insert(start);
        while (!q.empty()) {
            pair<double, string> cur = q.front();
            q.pop();

            if (cur.second == target) return cur.first;

            for (int i=0; i<graph[cur.second].size(); ++i) {
                if (visited.find(graph[cur.second][i].second) != visited.end()) continue;
                double newRes = cur.first * graph[cur.second][i].first;
                q.push({newRes, graph[cur.second][i].second});
                visited.insert(graph[cur.second][i].second);
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for (int i=0; i<n; ++i) {
            string first = equations[i][0];
            string second = equations[i][1];

            if (graph.find(first) == graph.end()) graph[first] = {};
            if (graph.find(second) == graph.end()) graph[second] = {};
            graph[first].push_back({values[i], second});
            graph[second].push_back({1.0/values[i], first});
        }

        vector<double> answer;
        for (int i=0; i<queries.size(); ++i) {
            answer.push_back(bfs(queries[i][0], queries[i][1]));
        }

        return answer;
    }
};


/*
Hash map + DFS.
Same approach but with DFS.
Time: O(Q*(V+E)).
Space: O(V+E).
*/
class Solution2 {
public:
    unordered_map<string, vector<pair<double, string>>> graph;
    unordered_set<string> visited;
    
    double dfs(string cur, string target, double total) {
        if (graph.find(cur) == graph.end() || graph.find(target) == graph.end()) return -1.0;
        if (cur == target) return total;
        visited.insert(cur);
        double answer = -1.0;
        for (int i=0; i<graph[cur].size(); ++i) {
            string next = graph[cur][i].second;
            double val = graph[cur][i].first;
            if (visited.find(next) == visited.end()) {
                double res = dfs(next, target, total * val);
                if (res != -1.0) answer = res;
            }
        }
        visited.erase(cur);

        return answer;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        for (int i=0; i<n; ++i) {
            string node1 = equations[i][0], node2 = equations[i][1];
            if (graph.find(node1) == graph.end()) graph[node1] = {};
            if (graph.find(node2) == graph.end()) graph[node2] = {};
            graph[node1].push_back({values[i], node2});
            graph[node2].push_back({1.0 / values[i], node1}); 
        }

        vector<double> answer;
        int m = queries.size();
        for (int j=0; j<m; ++j) {
            visited.clear();
            answer.push_back(dfs(queries[j][0], queries[j][1], 1.0));
        }

        return answer;
    }
};
