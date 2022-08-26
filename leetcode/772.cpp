#include <iostream>
#include <stack>
#include <queue>

using namespace std;


/*
The Shunting Yard Algorithm => Very useful for arithmetic problems!
Time: O(n)
Space: O(n)
The main idea of this algorithm is to convert the original expression into the reverse polish(postfix) notation.
https://brilliant.org/wiki/shunting-yard-algorithm
*/
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        string num;

        stack<string> st;
        queue<string> q;
        for (int i=0; i<n; ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                num += s[i];
            } else {
                if (num.size() > 0) {
                    q.push(num);
                    num = "";
                }

                if (s[i] == '(') {
                    st.push("(");
                } else if (s[i] == ')') {
                    while (st.top() != "(") {
                        q.push(st.top());
                        st.pop();
                    }
                    st.pop();
                } else {
                    if (s[i] == '+' || s[i] == '-') {
                        while (!st.empty() && st.top() != "(") {
                            q.push(st.top());
                            st.pop();
                        }
                    }
                    if (s[i] == '*' || s[i] == '/') {
                        while (!st.empty() && st.top() != "(" && st.top() != "+" && st.top() != "-") {
                            q.push(st.top());
                            st.pop();
                        }
                    }
                    if (s[i] == '+') st.push("+");
                    if (s[i] == '-') st.push("-");
                    if (s[i] == '*') st.push("*");
                    if (s[i] == '/') st.push("/");
                }
            }
        }
        if (num.size() > 0) {
            q.push(num);
        }
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }

        stack<int> res;
        while (!q.empty()) {
            string val = q.front();
            q.pop();
            if (val == "+" || val == "-" || val == "*" || val == "/") {
                int second = res.top();
                res.pop();
                int first = res.top();
                res.pop();

                if (val == "+") {
                    res.push(first + second);
                } else if (val == "-") {
                    res.push(first - second);
                } else if (val == "*") {
                    res.push(first * second);
                } else if (val == "/") {
                    res.push(first / second);
                }
            } else {
                res.push(stoi(val));
            }
        }

        return res.top();
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    int answer = sol->calculate(s);
    cout<<answer<<"\n";

    return 0;
}