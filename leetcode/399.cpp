#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;


class Solution {
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