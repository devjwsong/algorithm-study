#include <iostream>
#include <vector>

using namespace std;

/*
Dynamic Programming.
Time: O(m*n)
Space: O(m*n)
dp[i][j] means the minimum number of steps to convert word1[:i] into word2[:j].
And the final answer is dp[m][n].
dp[i][0] means that we should make word1[:i] into empty string, which is i.
Likewise, dp[0][j] is also j, since it means empty string is converted into word2[:j].
The rest of procedure is explained well in https://leetcode.com/problems/edit-distance/discuss/341904/Java-Solution-with-detail-explain.
*/
class Solution1 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
        
        for (int i=0; i<=m; ++i) {
            dp[i][0] = i;
        }
        for (int j=0; j<=n; ++j) {
            dp[0][j] = j;
        }
        
        for (int i=1; i<=m; ++i) {
            for (int j=1; j<=n; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    int ins = 1 + dp[i][j-1];
                    int del = 1 + dp[i-1][j];
                    int rep = 1 + dp[i-1][j-1];
                    dp[i][j] = min(rep, min(ins, del));
                }
            }
        }
        
        return dp[m][n];
    }
};


/*
Space optimized verstion.
Time: O(m*n)
Space: O(n)
This version's insight is that we don't need the whole table, since most of previous values are not used.
We just need the previous states and the current states.
Therefore, cur[j] menas the minimum number of steps for converting word1[:i] into word2[:j], and prev[j] is that of converting word1[:i-1] into words[:j].
Then, in the outer loop, we initialize cur[0] = i, since word1[:i] should be converted into an empty string.
The rest of updates are the same and finally prev should be updated into cur to save the current states for the next loop.
*/
class Solution2 {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> cur (n+1, 0);
        vector<int> prev (n+1, 0);
        
        for (int j=0; j<=n; ++j) {
            prev[j] = j;
        }
        
        for (int i=1; i<=m; ++i) {
            cur[0] = i;
            for (int j=1; j<=n; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    cur[j] = prev[j-1];
                } else {
                    int ins = 1 + cur[j-1];
                    int del = 1 + prev[j];
                    int rep = 1 + prev[j-1];
                    cur[j] = min(rep, min(ins, del));
                }
            }
            prev = cur;
        }
        
        return prev[n];
    }
};


int main() {

    string word1, word2;
    getline(cin, word1);
    getline(cin, word2);

    Solution1* sol1 = new Solution1();
    int answer = sol1->minDistance(word1, word2);
    cout<<answer<<"\n";

    Solution2* sol2 = new Solution2();
    answer = sol2->minDistance(word1, word2);
    cout<<answer<<"\n";

    return 0;
}