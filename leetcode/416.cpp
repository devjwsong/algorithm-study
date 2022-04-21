#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
        }

        if (sum % 2 == 1) return false;

        sum /= 2;

        vector<bool> dp (sum+1, false);
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] > sum) return false;

            for (int j=sum-nums[i]; j>=1; --j) {
                dp[j+nums[i]] = dp[j] || dp[j+nums[i]];
            }
            dp[nums[i]] = true;
        }

        return dp[sum];
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

    Solution* sol = new Solution();
    bool answer = sol->canPartition(nums);
    printf("%d\n", answer);

    return 0;
}