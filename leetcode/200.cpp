#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int moveRow[4] = {-1, 1, 0, 0};
    int moveCol[4] = {0, 0, -1, 1};

    int answer = 0;
    vector<vector<int>> tags;

    bool isValid(int r, int c, int m, int n) {
        return (r >= 0 && r < m && c >= 0 && c < n);
    }

    void search(vector<vector<char>>& grid, int r, int c, int tag) {
        int m = grid.size(), n = grid[0].size();
        
        tags[r][c] = tag;
        for (int d=0; d<4; ++d) {
            int nextR = r + moveRow[d];
            int nextC = c + moveCol[d];

            if (isValid(nextR, nextC, m, n) && grid[nextR][nextC] == '1' && tags[nextR][nextC] != tag) {
                search(grid, nextR, nextC, tag);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        tags.assign(m, vector<int> (n, 0));
        
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (tags[r][c] == 0 && grid[r][c] == '1') {
                    ++answer;
                    search(grid, r, c, answer);
                }
            }
        }

        return answer;
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
    int answer = sol->numIslands(grid);
    printf("%d\n", answer);

    return 0;
}