#include <iostream>
#include <vector>

using namespace std;


/*
Dynamic Programming.
Time: O(n).
Space: O(n).
dp[i][0]: the maximum profit when I don't have a stock at i.
dp[i][1]: the maximum profit when I have a stock at i.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;
        if (n == 2) return max(0, prices[1] - prices[0]);
        
        vector<vector<int>> dp (n, vector<int> (2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = max(dp[0][1], - prices[1]);
        for (int i=2; i<n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        }
        
        return max(dp[n-1][0], dp[n-1][1]);
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> prices;
    for (int i=0; i<n; ++i) {
        int val;
        scanf("%d", &val);
        prices.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->maxProfit(prices);
    printf("%d\n", answer);

    return 0;
}