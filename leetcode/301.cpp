#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;


/*
Be careful when conducting DP! It might ignore the path even if the path is not fully searched.
For example, ())((() can be made by removing the first ) or the second ) from ()))((().
DP can ignore the second emerging ())(((), so it is safe to use BFS approach, 
which spreads from the current string as much as possible.
*/
class Solution {
public:
    unordered_set<string> res;
    unordered_set<string> dp;
    int numRemoves = 0;

    int getRemoves(string& s) {
        stack<char> st;
        for (int i=0; i<s.size(); ++i) {
            if (s[i] == '(') {
                st.push('(');
            } else if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else {
                    st.push(')');
                }
            }
        }

        return st.size();
    }

    void solve(string& cur) {
        if (dp.find(cur) != dp.end()) return;
        dp.insert(cur);

        if (numRemoves == 0) {
            if (getRemoves(cur) == 0) res.insert(cur);
            return;
        }

        int n = cur.size();
        for (int i=0; i<n; ++i) {
            string temp = cur.substr(0, i) + cur.substr(i+1);
            --numRemoves;
            solve(temp);
            ++numRemoves;
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        numRemoves = getRemoves(s);
        solve(s);

        vector<string> answer;
        for (auto iter=res.begin(); iter!=res.end(); ++iter) {
            answer.push_back(*iter);
        }

        return answer;
    }
};


int main() {
    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    vector<string> answer = sol->removeInvalidParentheses(s);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<"\n";

    return 0;
}