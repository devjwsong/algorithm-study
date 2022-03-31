#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> dp;
        for (int i=0; i<nums.size(); ++i) {
            dp.push_back(vector<int> (2, 0));
        }

        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        for (int i=1; i<nums.size(); ++i) {
            int maxVal = max(max(dp[i-1][0] * nums[i], dp[i-1][1] * nums[i]), nums[i]);
            int minVal = min(min(dp[i-1][0] * nums[i], dp[i-1][1] * nums[i]), nums[i]);
            dp[i][0] = minVal;
            dp[i][1] = maxVal;
        }

        int answer = -1 * INT32_MAX;
        for (int i=0; i<nums.size(); ++i) {
            answer = max(answer, dp[i][1]);
        }

        return answer;
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
    int answer = sol->maxProduct(nums);
    printf("%d\n", answer);

    return 0;
}