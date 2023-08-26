#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


/*
BFS.
One tricky thing is converting the cell number into the row and column.
It can be handled by induction from the rule.
The rest is implementing BFS to find the shortest path to n*n.
Note that the condition says "do not take multiple ladders or snakes"!.
So it is enough to switch the next cell only when pushing the queue.
Making take the ladder or snake when we reach a cell will make a wrong answer.
Time: O(n*n).
Space: O(n*n).
*/
class Solution {
public:
    pair<int, int> num2Coord(int n, int num) {
        int r = (n-1) - ((num-1) / n);
        int c = (num-1) % n;
        if ((n + r) % 2 == 0) {
            c = (n-1) - c;
        }
        return {r,c};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        unordered_map<int, int> dists;
        queue<int> q;
        q.push(1);
        dists[1] = 0;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == n*n) return dists[cur];

            int minNext = cur+1;
            int maxNext = min(cur+6, n*n);
            for (int k=minNext; k<=maxNext; ++k) {
                pair<int, int> coords = num2Coord(n, k);
                int next = k;
                if (board[coords.first][coords.second] != -1) {
                    next = board[coords.first][coords.second];
                } 
                if (dists.find(next) == dists.end()) {
                    q.push(next);
                    dists[next] = dists[cur] + 1;
                }
            }
        }

        return -1;
    }
};
