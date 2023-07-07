#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


/*
Sorting + Resursion + Dynamic Programming.
1. By sorting the array, we don't need to think about erasing nums[i]-1, which is automatically ignored.
Also, it is much easier to detect nums[i]+1.
2. dp[i] contains the maximum sum at the index i.
One thing to consider is that we can add nums[i] or not.
The dp[i] array does not assume that we must include nums[i].
*/
class Solution1 {
public:
    vector<int> dp;

    int search(vector<int>& nums, int idx) {
        int n = nums.size();
        if (idx == n) return 0;
        if (dp[idx] > 0) return dp[idx];

        int cur = nums[idx];
        int curSum = 0;
        int iter = idx;
        while (iter < n && nums[iter] == cur) {
            curSum += nums[iter];
            ++iter;
        }

        int res = curSum;
        while (iter < n && nums[iter] == cur+1) {
            ++iter;
        }

        return dp[idx] = max(curSum + search(nums, iter), search(nums, idx+1));
    }

    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        dp.assign(n, 0);

        return search(nums, 0);
    }
};


/*
Dynamic Programming (not with the indices, but the values).
dp[v] means the maxmium value we can get when we consider the value in the array to maximum v.
Also note that it doesn't mean that the value v is necessarily included. (v might not be in the array at all!)
*/
class Solution2 {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp (10001, 0);
        vector<int> sums (10001, 0);
        int n = nums.size();
        for (int i=0; i<n; ++i) {
            sums[nums[i]] += nums[i];
        }

        dp[1] = sums[1];
        for (int v=2; v<=10000; ++v) {
            dp[v] = max(dp[v], max(dp[v-1], dp[v-2] + sums[v]));
        }

        return dp[10000];
    }
};
