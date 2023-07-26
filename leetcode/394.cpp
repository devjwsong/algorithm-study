#include <iostream>
#include <ctype.h>
#include <stack>

using namespace std;


/*
Stack + Recursion.
The point here is how to detect the substring to process covered by outer [].
*/
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string answer;
        string countStr;
        int i = 0;
        while (i < n) {
            if (s[i]>='0' && s[i]<='9') {
                countStr += s[i];
                ++i;
            } else if (s[i] == '[') {
                int count = stoi(countStr);
                countStr.clear();
                string sub;

                stack<char> st;
                int j = i;
                st.push(s[j]);
                ++j;

                while (!st.empty()) {
                    sub.push_back(s[j]);
                    if (s[j] == '[') {
                        st.push(s[j]);
                    } else if (s[j] == ']') {
                        st.pop();
                    }
                    ++j;
                }
                sub.pop_back();
                string res = decodeString(sub);
                for (int c=0; c<count; ++c) {
                    answer += res;
                }
                i = j;
            } else {
                answer += s[i];
                ++i;
            }
        }

        return answer;
    }
};
