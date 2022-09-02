#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int answer = 0;
    int rowDirs[4] = {-1, 1, 0, 0};
    int colDirs[4] = {0, 0, -1, 1};
    
    void search(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        grid[r][c] = '0';
        for (int d=0; d<4; ++d) {
            int nextR = r + rowDirs[d];
            int nextC = c + colDirs[d];
            
            if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n) {
                if (grid[nextR][nextC] == '1') {
                    search(grid, nextR, nextC);
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (grid[r][c] == '1') {
                    ++answer;
                    search(grid, r, c);
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