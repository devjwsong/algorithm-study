#include <iostream>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n < 2) return 0;
        
        stack<int> st;
        for (int i=0; i<n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty() && s[st.top()] == '(') {
                    st.pop();
                } else {
                    st.push(i);
                }
            }
        }
        
        if (st.empty()) return n;
        int next = st.top();
        int answer = max(0, n-1-next);
        
        st.pop();
        while (!st.empty()) {
            int cur = st.top();
            answer = max(answer, next-cur-1);
            next = cur;
            st.pop();
        }
        answer = max(answer, next);
        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    int answer = sol->longestValidParentheses(sol);
    cout<<answer<<"\n";

    return 0;
}