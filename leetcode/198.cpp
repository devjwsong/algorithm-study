#include <iostream>
#include <vector>

using namespace std;


/*
Dynamic Programming.
dp[i][0]: maximum amount by ith house if I don't rob the ith house.
dp[i][1]: maximum amount by ith house if I rob the ith house.
Note that the dp values naively increase while iterating,
since nums[i] >= 0 and by the definition, dp vector includes all previous calculations.
Time: O(n).
Space: O(n).
*/
class Solution1 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> dp (n, vector<int> (2, 0));

        dp[0][1] = nums[0];
        for (int i=1; i<n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            dp[i][1] = max(dp[i][1], dp[i-1][0] + nums[i]);
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};


/*
Dynamic Programming (without dp array!).
res0 <=> dp[i][0], res1 <=> dp[i][1].
If the dp array is incremental, that means it can be replaced with the constant values,
since eventually the last values would include the previously calculated optimal answers.
Time: O(n).
Space: O(1).
*/
class Solution2 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        
        int res0 = 0;
        int res1 = 0;

        res1 = nums[0];
        for (int i=1; i<n; ++i) {
            int temp = max(res0, res1);
            res1 = res0 + nums[i];
            res0 = temp;
        }

        return max(res0, res1);
    }
};

