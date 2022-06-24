#include <iostream>
#include <vector>

using namespace std;


// Recursion + Memoization.
class Solution1 {
public:
    vector<vector<int>> dp;
    bool search(string &s, string &p, int si, int pi) {
        int m = s.size(), n = p.size();
        if (si >= m && pi >= n) return true;
        if (pi >= n) return false;
        if (si >= m) {
            while (pi < n) {
                if (p[pi] != '*') return false;
                ++pi;
            }
            return true;
        }
        if (dp[si][pi] != -1) return dp[si][pi];
        
        if (p[pi] == '*') {
            return dp[si][pi] = search(s, p, si+1, pi) || search(s, p, si, pi+1);
        } else if (s[si] == p[pi] || p[pi] == '?') {
            return dp[si][pi] = search(s, p, si+1, pi+1);
        }
        return dp[si][pi] = false;
    }
    
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        dp.assign(m, vector<int> (n, -1));
        return search(s, p, 0, 0);
    }
};


/*
Tabulation + Memoization.
Here, the index is not based on the actual index, but on the length.
Since the base case is quite complicated, setting padding and initializing is much more intuitive.
*/
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp (m+1, vector<bool> (n+1, false));
        dp[0][0] = true;
        for (int pi=1; pi<=n; ++pi) {
            if (p[pi-1] == '*') {
                dp[0][pi] = true;
            } else {
                break;
            }
        }
        
        for (int si=1; si<=m; ++si) {
            for (int pi=1; pi<=n; ++pi) {
                if (s[si-1] == p[pi-1] || p[pi-1] == '?') {
                    dp[si][pi] = dp[si-1][pi-1];
                } else if (p[pi-1] == '*') {
                    dp[si][pi] = dp[si-1][pi] || dp[si][pi-1];
                }
            }
        }
        
        return dp[m][n];
    }
};


int main() {

    string s, p;
    getline(cin, s);
    getline(cin, p);

    Solution1* sol1 = new Solution1();
    bool answer = sol1->isMatch(s, p);
    cout<<answer<<"\n";

    Solution2* sol2 = new Solution2();
    answer = sol2->isMatch(s, p);
    cout<<answer<<"\n";

    return 0;
}