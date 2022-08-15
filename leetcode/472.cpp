#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;


class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, int> dp;

    int decompose(string& word) {
        if (word == "") return 0;
        if (dp.find(word) != dp.end()) return dp[word];

        int res = INT32_MIN;
        for (int i=0; i<word.size(); ++i) {
            string s = word.substr(0, i+1);
            if (dict.find(s) != dict.end()) {
                string next = word.substr(i+1);
                res = max(res, decompose(next) + 1);
            }
        }

        return dp[word] = res;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        for (int i=0; i<n; ++i) {
            dict.insert(words[i]);
        }

        vector<string> answer;

        for (int i=0; i<n; ++i) {
            int res = decompose(words[i]);
            if (res > 1) answer.push_back(words[i]);
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);
    getchar();

    vector<string> words;
    for (int i=0; i<n; ++i) {
        string s;
        getline(cin, s);
        words.push_back(s);
    }

    Solution* sol = new Solution();
    vector<string> answer = sol->findAllConcatenatedWordsInADict(words);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}