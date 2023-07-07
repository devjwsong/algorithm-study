#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int search(vector<vector<int>>& triangle, int r, int c) {
        if (dp[r][c] != INT_MAX) return dp[r][c];
        int R = triangle.size();
        if (r == R-1) return triangle[r][c];

        int newSum = triangle[r][c] + min(search(triangle, r+1, c), search(triangle, r+1, c+1));
        return dp[r][c] = min(dp[r][c], newSum);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int R = triangle.size();
        for (int r=0; r<R; ++r) {
            dp.push_back(vector<int> (r+1, INT_MAX));
        }

        return search(triangle, 0, 0);
    }
};
