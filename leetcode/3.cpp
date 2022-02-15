#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int answer = 0;

        unordered_map<char, int> m;
        string curStr = s.substr(0, 1);
        m[s[0]] = 0;
        int start = 0;
        for (int i=1; i<s.size(); ++i) {
            if (m.find(s[i]) != m.end()) {
                answer = max(answer, (int) curStr.size());
                int newStart = max(start, m[s[i]]+1);
                curStr = s.substr(newStart, i-newStart+1);
                m[s[i]] = i;
                start = newStart;
            } else {
                curStr += s.substr(i, 1);
                m[s[i]] = i;
            }
        }

        answer = max(answer, (int) curStr.size());

        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    int answer = sol->lengthOfLongestSubstring(s);

    printf("%d\n", answer);

    return 0;
}