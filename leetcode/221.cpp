#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxLen = 0;
    vector<vector<int>> dp;

    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        dp.assign(m, vector<int> (n, 0));
        
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (r == 0 || c == 0) {
                    if (matrix[r][c] == '1') dp[r][c] = 1;
                } else {
                    if (matrix[r][c] == '1') {
                        dp[r][c] = 1 + min(min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1]);
                    }
                }
                maxLen = max(maxLen, dp[r][c]);
            }
        }

        return maxLen * maxLen;
    }
};


int main() {

    int m, n;
    scanf("%d %d", &m, &n);

    vector<vector<char>> matrix;
    for (int r=0; r<m; ++r) {
        vector<char> row;
        for (int c=0; c<n; ++c) {
            char val;
            scanf(" %c", &val);
            row.push_back(val);
        }
        matrix.push_back(row);
    }

    Solution* sol = new Solution();
    int answer = sol->maximalSquare(matrix);
    printf("%d\n", answer);

    return 0;
}