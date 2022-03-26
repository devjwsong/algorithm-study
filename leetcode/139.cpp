#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp (s.size(), false);

        int start = 0;
        while(start < s.size()) {
            for (int i=0; i<wordDict.size(); ++i) {
                int wordLen = wordDict[i].size();
                if (s.substr(start, wordLen) == wordDict[i]) {
                    dp[start+wordLen-1] = true;
                }
            }

            bool isFound = false;
            for (int i=start; i<s.size(); ++i) {
                if (dp[i]) {
                    start = i+1;
                    isFound = true;
                    break;
                }
            }

            if (!isFound) break;
        }

        return dp[s.size()-1];
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