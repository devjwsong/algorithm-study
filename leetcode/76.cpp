#include <iostream>
#include <unordered_map>

using namespace std;


/*
Two pointer approach might be a little bit confusing.
But considering end is a standard, and start pointer just follows the end pointer.
If start surpasses end, it is fine since this case cannot be answer with count > 0;
Therefore, the end pointer will proceed anyway through the next iteration.
*/
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m) return "";

        unordered_map<char, int> char2num;
        for (int i=0; i<m; ++i) {
            ++char2num[t[i]];
        }

        int start = 0, end = 0;
        int pos = -1, curLen = n+1;
        int count = m;
        while (end < n) {
            if (char2num.find(s[end]) != char2num.end()) {
                if (char2num[s[end]] > 0) {
                    --count;
                }
                --char2num[s[end]];
            }

            while (count == 0) {
                if (curLen > end-start+1) {
                    pos = start;
                    curLen = end-start+1;
                }
                if (char2num.find(s[start]) != char2num.end()) {
                    ++char2num[s[start]];
                    if (char2num[s[start]] > 0) {
                        ++count;
                    }
                }
                ++start;
            }
            ++end;
        }

        if (pos == -1 || curLen == n+1) {
            return "";
        }
        return s.substr(pos, curLen);
    }
};


int main() {

    string s, t;
    getline(cin, s);
    getline(cin, t);

    Solution* sol = new Solution();
    string answer = sol->minWindow(s, t);
    cout<<answer<<"\n";

    return 0;
}