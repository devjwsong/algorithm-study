#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        if (row == n || column == n) return 0.0;
        if (k == 0) return 1.0;

        double dp[n][n][k+1];
        memset(dp, 0.0, sizeof(dp));
        dp[row][column][0] = 1.0;
        for (int i=0; i<k; ++i) {
            for (int r=0; r<n; ++r) {
                for (int c=0; c<n; ++c) {
                    if (dp[r][c][i] > 0) {
                        if (r-1 >= 0 && c-2 >= 0) dp[r-1][c-2][i+1] += (dp[r][c][i]/8.0);
                        if (r-2 >= 0 && c-1 >= 0) dp[r-2][c-1][i+1] += (dp[r][c][i]/8.0);
                        if (r-2 >= 0 && c+1 < n) dp[r-2][c+1][i+1] += (dp[r][c][i]/8.0);
                        if (r-1 >= 0 && c+2 < n) dp[r-1][c+2][i+1] += (dp[r][c][i]/8.0);
                        if (r+1 < n && c+2 < n) dp[r+1][c+2][i+1] += (dp[r][c][i]/8.0);
                        if (r+2 < n && c+1 < n) dp[r+2][c+1][i+1] += (dp[r][c][i]/8.0);
                        if (r+2 < n && c-1 >= 0) dp[r+2][c-1][i+1] += (dp[r][c][i]/8.0);
                        if (r+1 < n && c-2 >= 0) dp[r+1][c-2][i+1] += (dp[r][c][i]/8.0);
                    }
                }
            }
        }

        double answer = 0.0;
        for (int r=0; r<n; ++r) {
            for (int c=0; c<n; ++c) {
                answer += dp[r][c][k];
            }
        }
        return answer;
    }
};


int main() {

    int n, k, row, column;
    scanf("%d %d %d %d", &n, &k, &row, &column);

    Solution* sol = new Solution();
    double answer = sol->knightProbability(n, k, row, column);
    printf("%lf\n", answer);

    return 0;
}