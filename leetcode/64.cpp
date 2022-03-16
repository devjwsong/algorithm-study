#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m][n];
        dp[0][0] = grid[0][0];

        for (int c=1; c<n; ++c) {
            dp[0][c] = dp[0][c-1] + grid[0][c];
        }
        for (int r=1; r<m; ++r) {
            dp[r][0] = dp[r-1][0] + grid[r][0];
        }

        for (int r=1; r<m; ++r) {
            for (int c=1; c<n; ++c) {
                dp[r][c] = min(dp[r-1][c] + grid[r][c], dp[r][c-1] + grid[r][c]);
            }
        }

        return dp[m-1][n-1];
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
            scanf(" %d", &val);
            row.push_back(val);
        }
        grid.push_back(row);
    }

    Solution *sol = new Solution();
    int answer = sol->minPathSum(grid);
    printf("%d\n", answer);

    return 0;
}