#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int inf = INT32_MAX;
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        for (int i=0; i<n; ++i) {
            dp[i] = inf;
        }
        dp[0] = 0;

        for (int i=0; i<n-1; ++i) {
            int val = nums[i];
            for (int j=i+1; j<=i+val; ++j) {
                if (j < n) {
                    dp[j] = min(dp[j], dp[i] + 1);
                }
            }
        }

        return dp[n-1];
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
    int answer = sol->jump(nums);
    printf("%d\n", answer);

    return 0;
}