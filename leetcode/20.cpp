#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    stack<char> st;

    bool isValid(string s) {
        for (int i=0; i<s.length(); ++i) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }

                if (s[i] == ')') {
                    if (st.top() == '(') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else if (s[i] == '}') {
                    if (st.top() == '{') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else if (s[i] == ']') {
                    if (st.top() == '[') {
                        st.pop();
                    } else {
                        return false;
                    }
                }
            }
        }

        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};


int main() {

    string input;
    getline(cin, input);

    Solution *sol = new Solution();
    printf("%d\n", sol->isValid(input));

    return 0;
}