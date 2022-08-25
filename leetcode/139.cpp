#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp (n, false);
        int start = 0;
        while (start < n) {
            for (int i=0; i<wordDict.size(); ++i) {
                int len = wordDict[i].size();
                if (s.substr(start, len) == wordDict[i]) {
                    if (start + len - 1 < n) dp[start+len-1] = true;
                }
            }

            bool isFound = false;
            for (int i=start; i<n; ++i) {
                if (dp[i]) {
                    start = i + 1;
                    isFound = true;
                    break;
                }
            }

            if (!isFound) break;
        }

        return dp[n-1];
    }
};


int main() {

    string s;
    getline(cin, s);

    int n;
    scanf("%d", &n);

    vector<string> wordDict;
    for (int i=0; i<n; ++i) {
        string word;
        getline(cin >> ws, word);
        wordDict.push_back(word);
    }

    Solution *sol = new Solution();
    bool answer = sol->wordBreak(s, wordDict);
    cout<<answer<<"\n";

    return 0;
}