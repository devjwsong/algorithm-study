#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int answer = 0;
    int rowDirs[4] = {-1, 1, 0, 0};
    int colDirs[4] = {0, 0, -1, 1};
    int cur = 0;
    
    void search(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        
        ++cur;
        answer = max(answer, cur);
        grid[r][c] = 2;
        
        for (int d=0; d<4; ++d) {
            int nextR = r + rowDirs[d];
            int nextC = c + colDirs[d];
            
            if (nextR >= 0 && nextR < m && nextC >= 0 && nextC < n) {
                if (grid[nextR][nextC] == 1) search(grid, nextR, nextC);
            }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n =grid[0].size();
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (grid[r][c] == 1) {
                    cur = 0;
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

    vector<vector<int>> grid;
    for (int r=0; r<m; ++r) {
        vector<int> row;
        for (int c=0; c<n; ++c) {
            int val;
            scanf("%d", &val);
            row.push_back(val);
        }
        grid.push_back(row);
    }

    Solution* sol = new Solution();
    int answer = sol->maxAreaOfIsland(grid);

    return 0;
}