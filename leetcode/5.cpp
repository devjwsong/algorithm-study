#include <iostream>
#include <vector>

using namespace std;


/*
dp[i][j]: is substring [i:j] palindrome?
Time: O(n^2)
Space: O(n^2)
*/ 
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp (n, vector<bool> (n, 0));
        
        int start = 0, maxLen = 0;
        for (int dist=0; dist<n; ++dist) {
            for (int i=0; i<n-dist; ++i) {
                if (dist == 0) {
                    dp[i][i+dist] = true;
                    maxLen = dist + 1;
                    start = i;
                } else if (dist == 1) {
                    if (s[i] == s[i+dist]) {
                        dp[i][i+dist] = true;
                        if (dist + 1 >= maxLen) {
                            maxLen = dist + 1;
                            start = i;
                        }
                    } else {
                        dp[i][i+dist] = false;
                    }
                } else {
                    if (dp[i+1][i+dist-1]) {
                        if (s[i] == s[i+dist]) {
                            dp[i][i+dist] = true;
                            if (dist + 1 >= maxLen) {
                                maxLen = dist + 1;
                                start = i;
                            }
                        } else {
                            dp[i][i+dist] = false;
                        }
                    }
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};
