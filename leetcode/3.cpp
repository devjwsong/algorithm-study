#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
A hash map is used to memorize the last index of each character.
And curStr is the current longest substring only containing unique letters.
If s[i] is not in m, then it is unique so there is no problem with including it.
If s[i] is in m, that means somewhere another same letter already showed up.
So first we update the answer and get the new starting point.
If current start is higher than m[s[i]]+1, m[s[i]] will be updated to the new index anyway so we keep the starting position.
If m[s[i]]+1 is higher, that means m[s[i]] is contained in curStr, 
so in order to start again we should set the new starting point to m[s[i]]+1.
*/
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