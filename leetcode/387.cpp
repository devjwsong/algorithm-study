#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        vector<int> note (26, n);

        for (int i=0; i<n; ++i) {
            char cur = s[i];
            if (note[cur-'a'] == n) {
                note[cur-'a'] = i;
            } else if (note[cur-'a'] != n+1 && note[cur-'a'] != n) {
                note[cur-'a'] = n+1;
            }
        }

        int answer = n;
        for (int i=0; i<26; ++i) {
            answer = min(answer, note[i]);
        }

        if (answer >= n) return -1;

        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    int answer = sol->firstUniqChar(s);
    cout<<answer<<"\n";

    return 0;
}