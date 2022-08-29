#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int xDirs[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int yDirs[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

    int minKnightMoves(int x, int y) {
        x = abs(x), y = abs(y);

        queue<vector<int>> q;
        unordered_map<int, unordered_map<int, bool>> visited;
        q.push({0, 0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();

            int numSteps = cur[0], curX = cur[1], curY = cur[2];
            if (curX == x && curY == y) {
                return numSteps;
            }

            for (int d=0; d<8; ++d) {
                int nextX = curX + xDirs[d];
                int nextY = curY + yDirs[d];

                /*
                This is the important part to optimize the algorithm.
                We want to get closer to the destination as much as possible.
                So one step should not go beyond the certain range.
                We don't want to go backward from the beginning, so (-2, -1) and (-1, -2) is not allowed during moving.
                And we don't wnat to go beyond the destination, which are (x+2, y) and (x, y+2).
                */
                if (!visited[nextX][nextY] && nextX >= -1 && nextX <= x+2 && nextY >= -1 && nextY <= y+2) {
                    q.push({numSteps+1, nextX, nextY});
                    visited[nextX][nextY] = true;
                }
            }
        }

        return -1;
    }
};


int main() {

    int x, y;
    scanf("%d %d", &x, &y);

    Solution* sol = new Solution();
    int answer = sol->minKnightMoves(x, y);
    printf("%d", answer);

    return 0;
}