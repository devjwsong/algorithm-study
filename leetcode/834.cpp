#include <iostream>
#include <vector>

using namespace std;


/*
Two DFSs. (Search + Dynamic Programming)
The vector counter contains the size of the substree whose root is i.
So during the first DFS, we naively update the answer since the sum of distance
gets larger by the size of the next subtree, since all distance should increase by 1.
However, this is a naive solution.
After updating the answer first, then we need to adjust it,
because moving from parent to child actually make a difference in (n - 2 * sizeOfChildTree).
This is because one move reduce the distance by sizeofChildTrees, but also incrase the distance from child to others by (n - sizeofChildTree).
Time: O(n).
Space: O(n).
*/
class Solution {
public:
    vector<int> answer, counter;
    vector<vector<int>> graph;

    void dfs1(int cur, int prev) {
        for (int i=0; i<graph[cur].size(); ++i) {
            int next = graph[cur][i];
            if (next != prev) {
                dfs1(next, cur);
                counter[cur] += counter[next];
                answer[cur] += (answer[next] + counter[next]);
            }
        }
        ++counter[cur];
    }

    void dfs2(int n, int cur, int prev) {
        for (int i=0; i<graph[cur].size(); ++i) {
            int next = graph[cur][i];
            if (next != prev) {
                answer[next] = answer[cur] + (n - 2 * counter[next]);
                dfs2(n, next, cur); 
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        answer.assign(n, 0);
        counter.assign(n, 0);
        graph.assign(n, {});
        for (int i=0; i<n-1; ++i) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        dfs1(0, -1);
        dfs2(n, 0, -1);

        return answer;
    }
};
