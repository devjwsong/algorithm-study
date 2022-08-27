#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> canTake;
    vector<bool> visited;

    void search(int cur) {
        if (visited[cur]) return;
        visited[cur] = true;

        bool preFinished = true;
        for (int i=0; i<graph[cur].size(); ++i) {
            search(graph[cur][i]);
            if (!canTake[graph[cur][i]]) {
                preFinished = false;
            }
        }

        if (preFinished) {
            canTake[cur] = true;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, vector<int> {});
        canTake.assign(numCourses, true);
        visited.assign(numCourses, false);
        for (int i=0; i<prerequisites.size(); ++i) {
            int first = prerequisites[i][0], second = prerequisites[i][1];
            graph[first].push_back(second);
            canTake[first] = false;
        }

        for (int i=0; i<numCourses; ++i) {
            search(i);
        }

        for (int i=0; i<numCourses; ++i) {
            if (!canTake[i]) return false;
        }
        return true;
    }
};


int main() {

    int numCourses;
    scanf("%d", &numCourses);

    int n;
    scanf("%d", &n);
    vector<vector<int>> prerequisites;
    for (int i=0; i<n; ++i) {
        int first, second;
        scanf("%d %d", &first, &second);
        prerequisites.push_back(vector<int> {first, second});
    }

    Solution* sol = new Solution();
    bool answer = sol->canFinish(numCourses, prerequisites);
    printf("%d\n", answer);

    return 0;
}