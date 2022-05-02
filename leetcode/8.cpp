#include <iostream>
#include <cmath>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        while(s[i] == ' ' && i < n) {
            ++i;
        }

        if (i == n) return 0;

        int sign = 1;
        if (s[i] == '+') {
            sign = 1;
            ++i;
        } else if (s[i] == '-') {
            sign = -1;
            ++i;
        }

        int answer = 0;
        while (i < n && s[i]-'0' >= 0 && s[i]-'0' <= 9) {
            int digit = s[i]-'0';

            if ((INT32_MAX - digit) / 10 < answer) {
                if (sign == 1) return INT32_MAX;
                if (sign == -1) return INT32_MIN;
            }
            answer = answer * 10 + digit;
            ++i;
        }

        return sign * answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    int answer = sol->myAtoi(s);
    cout<<answer<<"\n";

    return 0;
}