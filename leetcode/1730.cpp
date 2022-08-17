#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;


class Solution {
public:
    int rowDirs[4] = {-1, 1, 0, 0};
    int colDirs[4] = {0, 0, -1, 1};
    vector<vector<bool>> visited;

    struct Node {
        int curR;
        int curC;
        int count;

        Node(int _curR, int _curC, int _count) {
            curR = _curR;
            curC = _curC;
            count = _count;
        }
    };

    bool isValid(vector<vector<char>>& grid, int nextR, int nextC) {
        int m = grid.size(), n = grid[0].size();
        if (nextR < 0 || nextR >= m || nextC < 0 || nextC >= n) return false;
        if (grid[nextR][nextC] == 'X') return false;
        if (visited[nextR][nextC]) return false;

        return true;
    }

    int getFood(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        visited.assign(m, vector<bool> (n, false));

        int initR, initC;
        bool noFood = true;
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (grid[r][c] == '*') {
                    initR = r;
                    initC = c;
                }

                if (grid[r][c] == '#') noFood = false;
            }
        }
        if (noFood) return -1;
        
        queue<Node*> q;
        Node* init = new Node(initR, initC, 0);
        visited[initR][initC] = true;
        q.push(init);
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();

            if (grid[cur->curR][cur->curC] == '#') return cur->count;

            for (int d=0; d<4; ++d) {
                int nextR = cur->curR + rowDirs[d];
                int nextC = cur->curC + colDirs[d];

                if (isValid(grid, nextR, nextC)) {
                    Node* nextNode = new Node(nextR, nextC, cur->count+1);
                    visited[nextR][nextC] = true;
                    q.push(nextNode);
                }
            }
        }

        return -1;
    }
};


int main() {

    int m, n;
    scanf("%d %d", &m, &n);

    vector<vector<char>> grid;
    for (int r=0; r<m; ++r) {
        vector<char> row;
        for (int c=0; c<n; ++c) {
            char val;
            scanf(" %c", &val);
            row.push_back(val);
        }
        grid.push_back(row);
    }

    Solution* sol = new Solution();
    int answer = sol->getFood(grid);
    printf("%d\n", answer);

    return 0;
}