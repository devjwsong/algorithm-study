#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numSquares(int n) {
        vector<int> dp (n+1, 10001);
        int m = 1;
        while(m * m <= n) {
            dp[m*m] = 1;
            m += 1;
        }
        
        for (int i=1; i<=n; ++i) {
            if (dp[i] == 10001) {
                int j = 1;
                while(j * j <= i) {
                    dp[i] = min(dp[i], 1 + dp[i - j*j]);
                    ++j;
                }
            }
        }
        
        return dp[n];
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution* sol = new Solution();
    int answer = sol->numSquares(n);
    printf("%d\n", answer);

    return 0;
}