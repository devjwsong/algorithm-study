#include <iostream>
#include <ctype.h>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string answer;

        int cur = 0;
        while(cur < s.size()) {
            if (isdigit(s[cur]) > 0) {
                string numVal;
                for (int i=cur; i<s.size(); ++i) {
                    if (s[i] != '[') {
                        numVal += s[i];
                    } else {
                        cur = i;
                        break;
                    }
                }

                int num = stoi(numVal);
                string enc;
                stack<char> st;

                for (int i=cur; i<s.size(); ++i) {
                    if (s[i] == '[') {
                        st.push(s[i]);
                    } else if (s[i] == ']') {
                        st.pop();
                    }

                    enc += s[i];

                    if (st.empty()) {
                        cur = i+1;
                        break;
                    }
                }

                string decoded = decodeString(enc.substr(1, enc.size()-2));
                for (int i=0; i<num; ++i) {
                    answer += decoded;
                }
            } else {
                answer += s[cur];
                ++cur;
            }
        }

        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    string answer = sol->decodeString(s);
    cout<<answer<<"\n";

    return 0;
}