#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if (n < k || n == 0) return 0;
        if (k == 1) return n;

        int counts[26] = {0};
        for (int i=0; i<n; ++i) {
            ++counts[s[i]-'a'];
        }

        /* 
        The idea is that whatever we do, the alphabets which are not contained less than k cannot be a part of the substring.
        So, divide the string starting from the first character less than k and calculate each answer from left and right parts.
        */
        int idx = 0;
        while (idx < n && counts[s[idx]-'a'] >= k) {
            ++idx;
        }
        if (idx >= n) return n;
        int leftRes = longestSubstring(s.substr(0, idx), k);

        while (idx < n && counts[s[idx]-'a'] < k) {
            ++idx;
        }
        int rightRes = 0;
        if (idx < n) {
            rightRes = longestSubstring(s.substr(idx, n-idx), k);
        }

        return max(leftRes, rightRes);
    }
};


int main() {

    string s;
    getline(cin, s);

    int k;
    cin>>k;

    Solution* sol = new Solution();
    int answer = sol->longestSubstring(s, k);
    cout<<answer<<"\n";

    return 0;
}