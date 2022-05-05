#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp (n, 0);

        if (s[0] != '0') dp[0] = 1;
        if (n == 1) return dp[0];

        if (s[1] != '0') dp[1] = dp[0];
        if (s.substr(0, 2) <= "26" && s[0] != '0') {
            ++dp[1];
        }

        for (int i=2; i<n; ++i) {
            if (s[i] != '0') dp[i] = dp[i-1];
            if (s.substr(i-1, 2) <= "26" && s[i-1] != '0') {
                dp[i] += dp[i-2];
            }
        }

        return dp[n-1];
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    int answer = sol->numDecodings(s);
    cout<<answer<<"\n";

    return 0;
}