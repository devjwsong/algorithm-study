#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp (n, vector<int> (n, 0));  // 0: not palindrome, 1: palindrome

        int maxStart = 0;
        int maxLen = 0;
        for (int dist=0; dist<n; ++dist) {
            for (int i=0; i<n-dist; ++i) {
                if (dist == 0) {
                    dp[i][i+dist] = 1;
                    if (dist+1 >= maxLen) {
                        maxLen = dist+1;
                        maxStart = i;
                    }
                }

                if (dist == 1) {
                    if (s[i] == s[i+dist]) {
                        dp[i][i+dist] = 1;
                        if (dist+1 >= maxLen) {
                            maxLen = dist+1;
                            maxStart = i;
                        }
                    } else {
                        dp[i][i+dist] = 0;
                    }
                }

                if (dist >= 2) {
                    if (dp[i+1][i+dist-1] == 1) {
                        if (s[i] == s[i+dist]) {
                            dp[i][i+dist] = 1;
                            if (dist+1 >= maxLen) {
                                maxLen = dist+1;
                                maxStart = i;
                            }
                        } else {
                            dp[i][i+dist] = 0;
                        }
                    }
                }
            }
        }

        return s.substr(maxStart, maxLen);
    }
};

int main() {

    string s;
    getline(cin, s);

    Solution *sol = new Solution();
    string answer = sol->longestPalindrome(s);

    cout<<answer + "\n";

    return 0;
}