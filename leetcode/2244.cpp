#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Sorting + Dynamic Programming.
Time: O(nlogn).
Space: O(n).
*/
class Solution1 {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end());

        vector<int> dp (n, -1);
        if (n >= 2) {
            if (tasks[0] == tasks[1]) dp[1] = 1;
        }
        if (n >= 3) {
            if (tasks[0] == tasks[2] && tasks[1] == tasks[2]) dp[2] = 1;
        }
        for (int i=3; i<n; ++i) {
            int cand1 = -1;
            if (dp[i-2] != -1) {
                if (tasks[i-1] == tasks[i]) cand1 = dp[i-2] + 1;
            }

            int cand2 = -1;
            if (dp[i-3] != -1) {
                if (tasks[i-2] == tasks[i] && tasks[i-1] == tasks[i]) cand2 = dp[i-3] + 1; 
            }

            if (cand1 != -1&& cand2 != -1) {
                dp[i] = min(cand1, cand2);
            } else if (cand1 == -1) {
                dp[i] = cand2;
            } else if (cand2 == -1) {
                dp[i] = cand1;
            }
        }

        return dp[n-1];
    }
};


/*
Sorting + Greedy.
Note that even if there are two loops, this runs actually one loop just like two pointers iteration.
Also when updating res, even if the remainder is 1, this would not be a problem.
If it is 1, then it can be considered 2+2, not 3+1.
So eventually the value of res becomes the same.
Time: O(nlogn).
Space: O(1).
*/
class Solution2 {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size();
        sort(tasks.begin(), tasks.end());

        int res = 0;
        int start = 0, end = 0;
        while (start < n) {
            for (end=start+1; end<n; ++end) {
                if (tasks[end] != tasks[start]) {
                    break;
                }
            }

            if (end-start == 1) return -1;
            res += ((end - start) / 3);
            if ((end - start) % 3 > 0) ++res;

            start = end;
        }

        return res;
    }
};
