#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


/*
BFS.
Starting from the gates, we mark the empty cells into the shortest path from any gate
which has been reached first.
One thing to discuss is that if we update the value before iterating the directions,
one test case throws TLE.
One possibility is a stack of redundant calculations, which means that if we don't update the value before pushing into the queue,
other nearby cell can update the path into it has calcuated so far.
So one cell might get signal from multiple adjacent cells and this will increase the number of branches to spread exponentially.
Time: O(m*n).
Space: O(m*n).
*/
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        int dirRows[4] = {-1, 1, 0, 0};
        int dirCols[4] = {0, 0, -1, 1};

        queue<vector<int>> q;
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (rooms[r][c] == 0) {
                    q.push({r,c,0});
                }
            }
        }

        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();

            int r = cur[0], c = cur[1], count = cur[2];
            if (rooms[r][c] > count) rooms[r][c] = count;

            for (int d=0; d<4; ++d) {
                int nextR = cur[0] + dirRows[d];
                int nextC = cur[1] + dirCols[d];

                if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n) {
                    if (rooms[nextR][nextC] == INT_MAX) {
                        rooms[nextR][nextC] = count+1;
                        q.push({nextR, nextC, count+1});
                    }
                }
            }
        }
    }
};