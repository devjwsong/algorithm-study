#include <iostream>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int answer = 0;
        for (int i=n-1; i>=0; --i) {
            if (s[i] == ' ') {
                if (answer > 0) break;
            } else {
                ++answer;
            }
        }

        return answer;
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