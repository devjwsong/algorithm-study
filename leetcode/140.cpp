#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    unordered_set<string> dict;
    vector<bool> dp;
    vector<string> answer;
    
    void search(string& s, int idx, string cur) {
        if (idx >= s.size()) {
            answer.push_back(cur);
            return;
        }
        
        bool poss = false;
        for (int i=idx; i<s.size(); ++i) {
            string temp = s.substr(idx, i-idx+1);
            string next = cur;
            if (dict.find(temp) != dict.end()) {
                if (cur.size() == 0) {
                    next = temp;
                } else {
                    next += " ";
                    next += temp;
                }
                poss = true;
                if (i+1 < s.size() && !dp[i+1]) continue;
                search(s, i+1, next);
            }
        }
        
        if (!poss) dp[idx] = false;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (int i=0; i<wordDict.size(); ++i) {
            dict.insert(wordDict[i]);
        }
        dp.assign(s.size(), true);
        
        string cur;
        search(s, 0, cur);
        
        return answer;    
    }
};


int main() {

    string s;
    getline(cin, s);

    int n;
    cin>>n;
    getchar();
    
    vector<string> wordDict;
    for (int i=0; i<n; ++i) {
        string val;
        getline(cin, val);
        wordDict.push_back(val);
    }

    Solution* sol = new Solution();
    vector<string> answer = sol->wordBreak(s, wordDict);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}