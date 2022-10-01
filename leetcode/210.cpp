#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> possible;
    vector<bool> visited;
    vector<int> answer;
    bool isCycle = false;

    bool search(int course) {
        if (possible[course]) {
            return true;
        } else {
            if (visited[course]) {
                isCycle = true;
                return false;
            }
        }
        visited[course] = true;
        if (graph[course].size() == 0) {
            possible[course] = true;
            answer.push_back(course);
            return true;
        }

        bool res = true;
        for (int i=0; i<graph[course].size(); ++i) {
            int pre = graph[course][i];
            if (!search(pre)) {
                res = false;
            }
        }

        if (res) {
            possible[course] = true;
            answer.push_back(course);
        }
        return res;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        graph.assign(numCourses, vector<int> {});
        possible.assign(numCourses, false);
        visited.assign(numCourses, false);

        int n = prerequisites.size();
        for (int i=0; i<n; ++i) {
            int target = prerequisites[i][0];
            int pre = prerequisites[i][1];
            graph[target].push_back(pre);
        }

        for (int i=0; i<numCourses; ++i) {
            search(i);
        }

        if (isCycle) return {};
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