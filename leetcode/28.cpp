#include <iostream>
#include <vector>

using namespace std;

/*
KMP algorithm.
Time: O(m+n)
Space: O(n)
*/
class Solution {
public:
    /*
    This part is the most difficult...
    The idea is using the previous pi value to calculate a new pi value of current index.
    That is, it is another KMP algorithm but matching needle with needle.
    If needle[i] != needle[j], move j into pi[j-1], which is the length of prefix of [0:j-1].
    If needle[i] == needle[i], the length of prefix + 1(j) becomes the pi[i].
    */
    vector<int> getPi(string& needle) {
        int n = needle.size();
        vector<int> pi (n, 0);
        int j = 0;
        for (int i=1; i<n; ++i) {
            while (j > 0 && needle[i] != needle[j]) {
                j = pi[j-1];
            }

            if (needle[i] == needle[j]) {
                pi[i] = j+1;
                ++j;
            }
        }

        return pi;
    }

    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (m < n) return -1;
    
        vector<int> pi = getPi(needle);
        int cur = 0, matched = 0;
        while (cur < m) {
            if (haystack[cur+matched] == needle[matched]) {
                ++matched;

                if (matched == n) return cur;
            } else {
                if (matched == 0) {
                    ++cur;
                } else {
                    cur += (matched - pi[matched-1]);
                    matched = pi[matched-1];
                }
            }
        }

        return -1;
    }
};


int main() {

    string haystack;
    string needle;

    getline(cin, haystack);
    getline(cin, needle);

    Solution *sol = new Solution();
    int answer = sol->strStr(haystack, needle);

    printf("%d\n", answer);

    return 0;
}