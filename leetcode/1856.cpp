#include <iostream>
#include <vector>
#include <stack>

using namespace std;


/*
Prefix sum + Monotonic stack.
1. The array sums contains the prefix sums. sums[i] = the sum of values from 0 ~ i-1. (sums[0] = 0)
The reason why the index is added by 1 is just for the ease of calculation. (ex. sums[4] - sums[1]: from index 1 ~ 3.)
2. The list lefts & rights are for containint the left/right boundary for the list where num[i] is considered to be minimum.
Since the values are all positive and so to make the minimum * sum as maximum, we should keep the list size as long as possble for each minimum.
Using a monotonic stack, we trace the value and the number of values to be included in the maximum length list if the minimum is nums[i].
Time: O(n).
Space: O(n).
*/
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sums (n+1, 0);
        for (int i=0; i<n; ++i) {
            sums[i+1] = sums[i] + nums[i];
        }

        vector<int> lefts (n, 0),  rights (n, 0);
        stack<pair<int, int>> st;
        for (int i=0; i<n; ++i) {
            int count = 0;
            while (!st.empty() && st.top().first >= nums[i]) {
                ++count;
                count += st.top().second;
                st.pop();
            }
            st.push({nums[i], count});
            lefts[i] = count;
        }
        st = stack<pair<int, int>>();
        for (int i=n-1; i>=0; --i) {
            int count = 0;
            while (!st.empty() && st.top().first >= nums[i]) {
                ++count;
                count += st.top().second;
                st.pop();
            }
            st.push({nums[i], count});
            rights[i] = count;
        }

        long long answer = 0;
        for (int i=0; i<n; ++i) {
            int start = i - lefts[i];
            int end = i + rights[i];
            answer = max(answer, nums[i] * (sums[end+1]-sums[start]));
        }

        return answer % 1000000007;
    }
};
