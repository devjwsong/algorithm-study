#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Infix notation => Postfix notation.
class Solution1 {
public:
    int cal(int val1, int val2, char op) {
        if (op == '+') {
            return val1 + val2;
        } else if (op == '-') {
            return val1 - val2;
        } else if (op == '*') {
            return val1 * val2;
        } else if (op == '/') {
            return val1 / val2;
        }

        return -1;
    }

    int getPriority(char op) {
        if (op == '*' || op == '/') {
            return 1;
        } else {
            return 0;
        }
    }

    int calculate(string s) {
        stack<char> ops;
        vector<string> seqs;

        string cur = "";
        for (int i=0; i<s.size(); ++i) {
            if (s[i] >= 48 && s[i] <= 57) {
                cur += s[i];
            } else {
                if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                    if (cur.size() > 0) {
                        seqs.push_back(cur);
                        cur = "";
                    }

                    while (!ops.empty() && (getPriority(ops.top()) >= getPriority(s[i]))) {
                        char op = ops.top();
                        ops.pop();
                        string d;
                        d += op;
                        seqs.push_back(d);
                    }
                    ops.push(s[i]);
                }
            }
        }
        if (cur.size() > 0) {
            seqs.push_back(cur);
        }

        while (!ops.empty()) {
            string d;
            d += ops.top();
            seqs.push_back(d);
            ops.pop();
        }

        stack<int> nums;
        for (int i=0; i<seqs.size(); ++i) {
            if (seqs[i] == "+" || seqs[i] == "-" || seqs[i] == "*" || seqs[i] == "/") {
                int val2 = nums.top();
                nums.pop();
                int val1 = nums.top();
                nums.pop();

                if (seqs[i] == "+") {
                    nums.push(val1 + val2);
                } else if (seqs[i] == "-") {
                    nums.push(val1 - val2);
                } else if (seqs[i] == "*") {
                    nums.push(val1 * val2);
                } else {
                    nums.push(val1 / val2);
                }
            } else {
                nums.push(stoi(seqs[i]));
            }
        }

        return nums.top();
    }
};


// More simple method.
class Solution2 {
public:
    int cal(int val1, int val2, char op) {
        if (op == '+') {
            return val1 + val2;
        } else if (op == '-') {
            return val1 - val2;
        } else if (op == '*') {
            return val1 * val2;
        } else if (op == '/') {
            return val1 / val2;
        }

        return -1;
    }

    bool isOp(char c) {
        return c == '+' || c == '-' || c == '*' || c == '/'; 
    }

    int calculate(string s) {
        stack<int> st;
        int n = s.size();
        char sign = '+';

        for (int i=0; i<n; ++i) {
            if (isdigit(s[i])) {
                string cur = "";
                while (i < n && isdigit(s[i])) {
                    cur += s[i];
                    ++i;
                }
                --i;

                if (sign == '+') {
                    st.push(stoi(cur));
                } else if (sign == '-') {
                    st.push(-stoi(cur));
                } else if (sign == '*') {
                    int val = st.top();
                    st.pop();
                    st.push(val * stoi(cur));
                } else {
                    int val = st.top();
                    st.pop();
                    st.push(val / stoi(cur));
                }
            } else if (s[i] != ' ') {
                sign = s[i];
            }
        }

        int answer = 0;
        while (!st.empty()) {
            answer += st.top();
            st.pop();
        }

        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution1* sol1 = new Solution1();
    int answer = sol1->calculate(s);
    cout<<answer<<"\n";

    Solution2* sol2 = new Solution2();
    answer = sol2->calculate(s);
    cout<<answer<<"\n";

    return 0;
}