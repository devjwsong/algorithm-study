#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i=0; i<tokens.size(); ++i) {
            string token = tokens[i];
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int v2 = s.top();
                s.pop();
                int v1 = s.top();
                s.pop();
                if (token == "+") {
                    s.push(v1 + v2);
                } else if (token == "-") {
                    s.push(v1 - v2);
                } else if (token == "*") {
                    s.push(v1 * v2);
                } else {
                    s.push(v1 / v2);
                }
            } else {
                s.push(stoi(token));
            }
        }

        return s.top();
    }
};


int main() {

    int n;
    scanf("%d", &n);
    getchar();

    vector<string> tokens;
    for (int i=0; i<n; ++i) {
        string val;
        getline(cin, val);
        tokens.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->evalRPN(tokens);
    printf("%d\n", answer);

    return 0;
}