#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


class Solution {
public:
    unordered_set<string> dict;
    vector<string> answer;
    
    void search(string& s, int idx, string cur) {
        int n = s.size();
        if (idx >= n) {
            cur = cur.substr(1);
            answer.push_back(cur);
            return;
        }
        
        for (int i=idx; i<n; ++i) {
            string temp = s.substr(idx, i-idx+1);
            string next = cur;
            if (dict.find(temp) != dict.end()) {
                next += " ";
                next += temp;
                search(s, i+1, next);
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (int i=0; i<wordDict.size(); ++i) {
            dict.insert(wordDict[i]);
        }
        
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