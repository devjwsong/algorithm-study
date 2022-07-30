#include <iostream>
#include <string.h>

using namespace std;


// Recursive function can operate as a loop does!
class Solution {
public:
    int dp[20][30];
    bool search(string s, string p, int ss, int ps) {
        int m = s.size(), n = p.size();
        if (ss == m && ps == n) return true;
        if (ss == m) {
            while (ps < n-1) {
                if (p[ps] != '*' && p[ps+1] != '*') return false;
                ++ps;
            }
            return p[ps] == '*';
        }
        if (ps == n) return false;
    
        if (dp[ss][ps] != -1) { 
            return dp[ss][ps];
        }

        if (ps < n-1 && p[ps+1] == '*') {  // * matching but only the case of 0.
            if (search(s, p, ss, ps+2)) {
                return dp[ss][ps] = true;
            }
        }
        if (s[ss] == p[ps] || p[ps] == '.') {  // normal matching.
            if (search(s, p, ss+1, ps+1)) {
                return dp[ss][ps] = true;
            }
        }

        if (p[ps] == '*') {  // * matching passed from previous function.
            bool res1 = search(s, p, ss, ps+1);  // Finish *.
            bool res2 = false;
            if (ps > 0 && (s[ss] == p[ps-1] || p[ps-1] == '.')) {
                res2 = search(s, p, ss+1, ps);  // Keep *.
            }

            return dp[ss][ps] = res1 || res2;
        }

        return dp[ss][ps] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        memset(dp, -1, sizeof(dp));

        return search(s, p, 0, 0);
    }
};


int main() {

    string s, p;
    getline(cin, s);
    getline(cin, p);

    Solution* sol = new Solution();
    bool answer = sol->isMatch(s, p);
    cout<<answer<<"\n";

    return 0;
}