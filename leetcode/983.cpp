#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/*
Dynamic Programming.
1. If the current day is not included in the travel days, the minimum costs should be idential to the previous day,
since we don't spend any additional money.
2. Note that there is no need to iterate previous 7 or 30 days,
because obviously buying a new pass after consuming all available days would be more economical.
In other words, the dp vector happens to be monotonical by its definition, so it is advantageous to get the value from the smaller location.
Time: O(365).
Space: O(365).
*/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int end = days[n-1];
        vector<int> dp (end+1, 0);

        int idx = 0;
        for (int d=1; d<=end; ++d) {
            if (d == days[idx]) {
                int cand1 = dp[d-1] + costs[0];
                int cand2 = dp[max(0, d-7)] + costs[1];
                int cand3 = dp[max(0, d-30)] + costs[2];
                dp[d] = min(min(cand1, cand2), cand3);
                ++idx;
            } else {
                dp[d] = dp[d-1];
            }
        }

        return dp[end];
    }
};
