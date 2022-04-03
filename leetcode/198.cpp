#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp;
        for (int i=0; i<n; ++i) {
            dp.push_back(vector<int> (2, 0));
        }

        dp[0][0] = 0;
        dp[0][1] = nums[0];

        for (int i=1; i<n; ++i) {
            dp[i][0] = max(dp[i][0], dp[i-1][0]);
            dp[i][0] = max(dp[i][0], dp[i-1][1]);

            dp[i][1] = max(dp[i][1], dp[i-1][0] + nums[i]);
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> nums;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums.push_back(val);
    }

    Solution *sol = new Solution();
    int answer = sol->rob(nums);
    printf("%d\n", answer);

    return 0;
}