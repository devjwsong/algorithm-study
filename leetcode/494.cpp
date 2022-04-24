#include <iostream>
#include <vector>

using namespace std;

// DFS
class Solution1 {
public:
    int answer = 0;

    void search(vector<int>& nums, int idx, int target, int sum) {
        if (idx == nums.size()) {
            if (sum == target) ++answer;
            return;
        }

        int cur = nums[idx];
        search(nums, idx+1, target, sum + cur);
        search(nums, idx+1, target, sum - cur);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        search(nums, 0, target, 0);

        return answer;
    }
};


// DP
class Solution2 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int maxVal = 1000;
        vector<vector<int>> dp (nums.size(), vector<int> (maxVal * 2 + 1, 0));

        dp[0][nums[0] + maxVal] = 1;
        dp[0][-1 * nums[0] + maxVal] = 1;
        if (nums[0] == 0) dp[0][nums[0] + maxVal] += 1;

        for (int i=1; i<nums.size(); ++i) {
            for (int j=0; j<=maxVal*2; ++j) {
                if (dp[i-1][j] > 0) {
                    if (j + nums[i] <= 2 * maxVal) {
                        dp[i][j+nums[i]] += dp[i-1][j];
                    }
                    if (j - nums[i] >= 0) {
                        dp[i][j-nums[i]] += dp[i-1][j];
                    }
                }
            }
        }
        
        return dp[nums.size()-1][target+maxVal];
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

    int target;
    scanf("%d", &target);

    Solution1* sol1 = new Solution1();
    int answer = sol1->findTargetSumWays(nums, target);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->findTargetSumWays(nums, target);
    printf("%d\n", answer);

    return 0;
}