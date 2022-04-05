#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> answer;
    vector<vector<int>> graph;
    vector<bool> visited;
    vector<bool> canTake;

    void search(int cur) {
        if (!visited[cur] && canTake[cur]) {
            visited[cur] = true;
            answer.push_back(cur);
        } else {
            if (visited[cur]) return;
            if (!canTake[cur]) {
                visited[cur] = true;
                bool isPass = true;
                for (int j=0; j<graph[cur].size(); ++j) {
                    int next = graph[cur][j];
                    search(next);

                    if (!canTake[next]) isPass = false; 
                }

                if (isPass) {
                    canTake[cur] = true;
                    answer.push_back(cur);
                }
            }
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, vector<int> {});
        visited.assign(numCourses, false);
        canTake.assign(numCourses, true);
        for (int i=0; i<prerequisites.size(); ++i) {
            int first = prerequisites[i][0], second = prerequisites[i][1];
            graph[first].push_back(second);

            canTake[first] = false;
        }

        for (int i=0; i<numCourses; ++i) {
            search(i);
        }

        if (answer.size() < numCourses) return vector<int> {};

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
    vector<int> answer = sol->findOrder(numCourses, prerequisites);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}