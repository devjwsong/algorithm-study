#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<string>> answer;

    bool isPalindrome(string& s) {
        for (int i=0; i<s.size()/2; ++i) {
            if (s[i] != s[s.size()-i-1]) {
                return false;
            }
        }

        return true;
    }

    void dfs(string s, int start, vector<string>& soFar) {
        if (start == s.size()) {
            answer.push_back(soFar);
        } else {
            for (int end=start; end<s.size(); ++end) {
                string subS = s.substr(start, end-start+1);
                if (isPalindrome(subS)) {
                    soFar.push_back(subS);
                    dfs(s, end+1, soFar);
                    soFar.pop_back();
                }
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> init;
        dfs(s, 0, init);
        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    vector<vector<string>> answer = sol->partition(s);
    for (int i=0; i<answer.size(); ++i) {
        for (int j=0; j<answer[i].size(); ++j) {
            cout<<answer[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}