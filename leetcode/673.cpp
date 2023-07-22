#include <iostream>
#include <vector>

using namespace std;


/*
Dynamic Programming.
dp[i][0]: The maximum length of strictly increasing array ending with nums[i].
dp[i][1]: The number of the array whose length is maximum ending with nums[i].
Time: O(n^2).
Space: O(n).
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        
        vector<vector<int>> dp (n, vector<int> (2, 0));
        dp[0] = {1, 1};
        int maxLen = 0;

        for (int i=1; i<n; ++i) {
            int curMax = 1;
            int count = 1;
            for (int j=i-1; j>=0; --j) {
                if (nums[j] < nums[i]) {
                    if (curMax < dp[j][0] + 1) {
                        curMax = dp[j][0] + 1;
                        count = dp[j][1];
                    } else if (curMax == dp[j][0] + 1) {
                        count += dp[j][1];
                    }
                }
            }
            dp[i] = {curMax, count};
            maxLen = max(maxLen, curMax);
        }

        int answer = 0;
        for (int i=0; i<n; ++i) {
            if (dp[i][0] == maxLen) {
                answer += dp[i][1];
            }
        }

        return answer;
    }
};
