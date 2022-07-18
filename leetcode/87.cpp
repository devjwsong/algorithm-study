#include <iostream>
#include <string.h>

using namespace std;


/*
For optimization, a 4-D dp array is used in fixed length.
Also, substr makes the algorithm too slow, so it is better to use indices.
*/
class Solution {
public:
    int dp[30][30][30][30];

    bool canMake(string& s1, string& s2, int x, int y, int i, int j) {
        if (dp[x][y][i][j] != -1) return dp[x][y][i][j];
        if (x == y) {
            if (s1[x] == s2[i]) return true;
            return false;
        }

        for (int k=x; k<y; ++k) {
            bool l2l = canMake(s1, s2, x, k, i, i+(k-x));
            bool r2r = canMake(s1, s2, k+1, y, i+(k-x)+1, j);
            bool l2r = canMake(s1, s2, x, k, j-(k-x), j);
            bool r2l = canMake(s1, s2, k+1, y, i, i+(y-k)-1);

            if ((l2l && r2r) || (l2r && r2l)) {
                return dp[x][y][i][j] = true;
            }
        }

        return dp[x][y][i][j] = false;
    }

    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        int n = s1.size();
        return canMake(s1, s2, 0, n-1, 0, n-1);
    }
};


int main() {

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    Solution* sol = new Solution();
    bool answer = sol->isScramble(s1, s2);
    cout<<answer<<"\n";

    return 0;
}