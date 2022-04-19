#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[amount+1];
        dp[0] = 0;

        for (int i=1; i<=amount; ++i) {
            dp[i] = INT_MAX;
            for (int j=0; j<coins.size(); ++j) {
                int coin = coins[j];
                if (i-coin >= 0 && dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-coin]+1);
                }
            }
        }

        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];

    }
};


int main() {
    int n;
    scanf("%d", &n);

    vector<int> coins;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        coins.push_back(val);
    }

    int amount;
    scanf("%d", &amount);

    Solution* sol = new Solution();
    int answer = sol->coinChange(coins, amount);
    printf("%d\n", answer);

    return 0;
}