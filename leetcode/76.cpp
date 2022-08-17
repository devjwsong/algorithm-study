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
        int m = s.size(), n = t.size();
        if (m < n) return "";

        unordered_map<char, int> mp;
        for (int i=0; i<n; ++i) {
            ++mp[t[i]];
        }

        int start = 0, end = 0;
        int pos = -1, len = m+1;
        int count = n;
        while (end < m) {
            if (mp.find(s[end]) != mp.end()) {
                if (mp[s[end]] > 0) {
                    --count;
                }
                --mp[s[end]];
            }

            while (count == 0) {
                if (len > end - start + 1) {
                    pos = start;
                    len = end - start + 1;
                }
                if (mp.find(s[start]) != mp.end()) {
                    ++mp[s[start]];
                    if (mp[s[start]] > 0) {
                        ++count;
                    }
                }
                ++start;
            }

            ++end;
        }

        if (pos == -1 || len == m+1) return "";

        return s.substr(pos, len);
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