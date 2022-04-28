#include <iostream>
#include <cctype>

using namespace std;


class Solution {
public:
    bool isValid(char c) {
        return (int(c) >= 48 && int(c) <= 57) || (int(c) >= 65 && int(c) <= 90) || (int(c) >= 97 && int(c) <= 122);
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size()-1;
        while (i <= j) {
            bool resLeft = isValid(s[i]);
            bool resRight = isValid(s[j]);
            if (resLeft && resRight) {
                if (tolower(s[i]) != tolower(s[j])) return false;
                ++i;
                --j;
            } else if (!resLeft && resRight) {
                ++i;
            } else if (resLeft && !resRight) {
                --j;
            } else {
                ++i;
                --j;
            }
        }

        return true;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    bool answer = sol->isPalindrome(s);
    cout<<answer<<"\n";

    return 0;
}