#include <iostream>
#include <vector>

using namespace std;


/*
Dynamic Programming.
dp[i]: The length of the longest increasing subsequence within [0, i].
Time: O(n^2).
Space: O(n).
*/
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 1);
        dp[0] = 1;

        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        int answer = 1;
        for (int i=0; i<n; ++i) {
            answer = max(answer, dp[i]);
        }

        return answer;
    }
};


/*
Dynamic Programming with a trick!
Keep in mind the array mem does NOT contain the longest subsequence itself.
It just keeps the length.
If we find a value which is not larger than the maximum in mem,
we find the possible index which is the lower bound for equal or larger values to replace it.
Now, the length is kepts but mem has another possible fresh start for increasing subsequence.
If there are other values which can break the current maximum, the current maximum will be replace eventually,
and the length would be updated.
If not, even if mem does not have correct subsquence, the length memorizes the answer.
Time: O(nlogn).
Space: O(n).
*/
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> mem;

        for (int i=0; i<n; ++i) {
            if (mem.size() == 0 || mem.back() < nums[i]) {
                mem.push_back(nums[i]);
            } else {
                int idx = lower_bound(mem.begin(), mem.end(), nums[i]) - mem.begin();
                mem[idx] = nums[i];
            }
        }
        return mem.size();
    }
};