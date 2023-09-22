#include <iostream>
#include <queue>
#include <vector>

using namespace std;


/*
BFS + DFS.
First, for conveinence, we tag one of the two islands into 2 so that we can differentiate two different islands.
For tagging, we use DFS which is straightforward.
Next, we use BFS to find the minimum distance between two islands starting from the random point in the island 2.
Note that, we should put all cells in the island 2 because without it, some expansion will interrupt others
which results in inconsistent updates.
We should not expand to the island, but only to the water cell.
Time: O(n*m).
Space: O(n*m).
*/
class Solution {
public:
    vector<vector<bool>> visited;
    int rowDirs[4] = {-1, 1, 0, 0};
    int colDirs[4] = {0, 0, -1, 1};

    void tagIsland(vector<vector<int>>& grid, int row, int col) {
        if (grid[row][col] == 0) return;
        if (visited[row][col]) return;

        int n = grid.size(), m = grid[0].size();
        visited[row][col] = true;
        grid[row][col] = 2;

        for (int d=0; d<4; ++d) {
            int nextRow = row + rowDirs[d];
            int nextCol = col + colDirs[d];
            if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m) {
                tagIsland(grid, nextRow, nextCol);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        visited.assign(n, vector<bool> (m, false));

        int row = -1, col = -1;
        for (int r=0; r<n; ++r) {
            for (int c=0; c<m; ++c) {
                if (grid[r][c] == 1) {
                    row = r;
                    col = c;
                    break;
                }
            }
            if (row != -1 && col != -1) break;
        }
        tagIsland(grid, row, col);

        queue<vector<int>> q;
        for (int r=0; r<n; ++r) {
            for (int c=0; c<m; ++c) {
                if (visited[r][c]) {
                    q.push({r, c, grid[r][c], 0});
                } else {
                    visited[r][c] = false;
                }
            }
        }

        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();

            for (int d=0; d<4; ++d) {
                int nextRow = cur[0] + rowDirs[d];
                int nextCol = cur[1] + colDirs[d];
                if (nextRow >= 0 && nextRow < n && nextCol >= 0 && nextCol < m) {
                    if (!visited[nextRow][nextCol]) {
                        if (grid[nextRow][nextCol] == 0) {  // Water
                            q.push({nextRow, nextCol, cur[2], cur[3]+1});
                            visited[nextRow][nextCol] = true;
                        } else if (grid[nextRow][nextCol] == 1) {  // Another island
                            return cur[3];
                        }
                    }
                }
            }
        }

        return 0;
    }
};
