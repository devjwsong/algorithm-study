#include <iostream>
#include <vector>

using namespace std;


/*
Dynamic Programming + Game Tree.
First, I thought there should be a dp for player 2.
But it is not necessary, since this is a min-max tree, and we can update the maximum score of the player 1,
assuming that the next recursion is minimized by the player2.
Also, be careful to handle the case start > end, which does not usually happen for conventional DP problems,
but here, we might call (start+2, end) and (start, end-2).
Time: O(n^2).
Space: O(n^2).
*/
class Solution {
public:
    vector<vector<int>> dp;

    int getScore(vector<int>& nums, int start, int end) {
        if (start > end) return 0;
        if (dp[start][end] > -1) return dp[start][end];

        int left = nums[start] + min(getScore(nums, start+2, end), getScore(nums, start+1, end-1));
        int right = nums[end] + min(getScore(nums, start+1, end-1), getScore(nums, start, end-2));

        return dp[start][end] = max(left, right);
    }

    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int> (n, -1));
        int maxScore = getScore(nums, 0, n-1);
        int total = 0;
        for (int i=0; i<n; ++i) {
            total += nums[i];
        }

        return maxScore >= (total - maxScore);
    }
};
