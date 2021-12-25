#include <iostream>

using namespace std;


class Solution {
public:
    string strip(string s) {
        int idx = s.size();
        for (int i=s.size()-1; i>=0; --i) {
            if (s[i] != ' ') {
                idx = i;
                break;
            }
        }

        if (idx < s.size()-1) {
            s.erase(idx+1);
        }

        return s;
    }

    int lengthOfLastWord(string s) {
        string stripped = strip(s);

        int count = 0;
        for (int i=0; i<stripped.size(); ++i) {
            char c = stripped[i];
            if (c == ' ') {
                count = 0;
            } else {
                count += 1;
            }
        }

        return count;
    }
};


int main() {
    string s;
    getline(cin, s);

    Solution *sol = new Solution();
    int answer = sol->lengthOfLastWord(s);

    printf("%d\n", answer);

    return 0;
}