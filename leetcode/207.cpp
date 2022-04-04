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

    bool search(int cur) {
        if (canTake[cur]) return true;
        if (visited[cur]) return false;

        visited[cur] = true;
        bool pass = true;
        for (int j=0; j<graph[cur].size(); ++j) {
            int next = graph[cur][j];
            pass = pass && search(next);
        }

        visited[cur] = false;
        if (pass) {
            canTake[cur] = true;
            return true;
        } else {
            return false;
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, vector<int> {});
        canTake.assign(numCourses, true);
        visited.assign(numCourses, false);
        for (int i=0; i<prerequisites.size(); ++i) {
            int first = prerequisites[i][0], second = prerequisites[i][1];
            graph[second].push_back(first);

            canTake[second] = false;
        }

        bool answer = true;
        for (int i=0; i<numCourses; ++i) {
            answer = answer && search(i);
        }

        return answer;
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