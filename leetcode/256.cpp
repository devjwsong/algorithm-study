#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/*
Famous DP problem.
dp[i][j] = The minimum cost considering 0~ith houses and ith house is painted with jth color.
dp[i][j] = minimum among (dp[i-1][k] + costs[i][j]) (k != j)
Time: O(n).
Space: O(n).
*/
class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp (n, vector<int> (3, INT_MAX));

        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for (int i=1; i<n; ++i) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    if (k != j) {
                        dp[i][j] = min(dp[i][j], dp[i-1][k] + costs[i][j]);
                    }
                }
            }
        }

        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};
