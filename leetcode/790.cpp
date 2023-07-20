#include <iostream>
#include <vector>

using namespace std;


/*
Dynamic Programming + Math!
dp[k] = dp[k-1] + dp[k-2] + 2dp[k-3] + 2dp[k-4] + ... + 2dp[0].
dp[k-1] = dp[k-2] + d[k-3] + 2dp[k-4] + ... + 2dp[0].
=> dp[k] = 2dp[k-1] + dp[k-3].
Why? dp[k-1] and dp[k-2] are obvious.
In order to finish with Tromino, additional two cases pop up if one more domino is added.
For instance, k=3 => 2 cases with two trominoes.
k=4 => 2 same cases for k=3 + 2 additional cases with two trominoes and one domino.
k=5 => 2 same cases for k=4 + 2 additional cases with two trominoes and one domino....
Time: O(n).
Space: O(n).
*/
class Solution {
public:
    int numTilings(int n) {
        int m = 1000000007;
        vector<int> dp (n+1, 0);
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i=4; i<=n; ++i) {
            dp[i] = (2 * dp[i-1] % m + dp[i-3] % m) % m;
        }

        return dp[n];
    }
};
