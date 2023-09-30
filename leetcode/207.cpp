#include <iostream>
#include <vector>

using namespace std;


/*
DFS.
The idea is connecting a directed edge between the course and its prerequisite
and check if there is cycle.
If there is, that means there is a conflict between the courses.
Time: O(n^2).
Space: O(n^2).
*/
class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<bool> isTaken;

    bool dfs(int cur) {
        if (visited[cur]) {
            if (!isTaken[cur]) {
                return false;
            } else {
                return true;
            }
        }
        visited[cur] = true;

        for (int i=0; i<graph[cur].size(); ++i) {
            int next = graph[cur][i];
            if (!dfs(next)) return false;
        }

        return isTaken[cur] = true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, vector<int>());
        visited.assign(numCourses, false);
        isTaken.assign(numCourses, false);
        
        int n = prerequisites.size();
        for (int i=0; i<n; ++i) {
            int course = prerequisites[i][0], pre = prerequisites[i][1];
            graph[pre].push_back(course);
        }

        for (int i=0; i<numCourses; ++i) {
            if (!visited[i] && !dfs(i)) return false;
        }

        return true;
    }
};
