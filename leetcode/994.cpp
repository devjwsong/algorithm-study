#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/*
BFS.
The problem is converted into finding the shortest path from the fresh orange to any rotten one.
Then we fetch the maximum value among the calculated values for each fresh orange.
Time: O(m*n*m*n).
Space: O(m*n).
*/
class Solution1 {
public:
    int dirRows[4] = {-1, 1, 0, 0};
    int dirCols[4] = {0, 0, -1, 1};

    int bfs(vector<vector<int>> grid, int r, int c) {
        if (grid[r][c] == 2) return 0;

        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited (m, vector<bool> (n, false));
        queue<vector<int>> q;
        q.push({0, r, c});
        visited[r][c] = true;
        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            if (grid[cur[1]][cur[2]] == 2) return cur[0];

            for (int d=0; d<4; ++d) {
                int nextR = cur[1] + dirRows[d];
                int nextC = cur[2] + dirCols[d];
                if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n) {
                    if (grid[nextR][nextC] != 0 && !visited[nextR][nextC]) {
                        q.push({cur[0]+1, nextR, nextC});
                        visited[nextR][nextC] = true;
                    }
                }
            }
        }

        return -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int answer = 0;
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (grid[r][c] > 0) {
                    int res = bfs(grid, r, c);
                    if (res == -1) return -1;
                    answer = max(answer, res);
                }
            }
        }

        return answer;
    }
};


/*
BFS. (More optimized)
There is no need to run BFS for each fresh orange.
We can actually simulate the time as the problem condition.
So we run the BFS for each rotten orange using an inner loop.
This inner loop contraints the number of checkings only for the current branch.
Also, we mark the fresh one into a rotten, so there is no need for the matrix for visited spots.
Time: O(m * n).
Space: O(m * n).
*/
class Solution2 {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dirRows[4] = {-1, 1, 0, 0};
        int dirCols[4] = {0, 0, -1, 1};

        queue<pair<int, int>> q;
        int numFresh = 0;
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (grid[r][c] == 1) {
                    ++numFresh;
                } else if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        int answer = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size > 0) {
                pair<int, int> cur = q.front();
                q.pop();

                for (int d=0; d<4; ++d) {
                    int nextR = cur.first + dirRows[d];
                    int nextC = cur.second + dirCols[d];

                    if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n) {
                        if (grid[nextR][nextC] == 1) {
                            grid[nextR][nextC] = 2;
                            q.push({nextR, nextC});
                            --numFresh;
                        }
                    }
                }

                --size;
            }
            ++answer;
        }

        if (numFresh > 0) return -1;
        if (answer == 0) return answer;
        return answer-1;
    }
};