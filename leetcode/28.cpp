// KMP Algorithm

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> getPi(string needle) {
        vector<int> pi (needle.size(), 0);
        int j = 0;
        for (int i=1; i<needle.size(); ++i) {
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
        if (needle.size() == 0) {
            return 0;
        } else if (haystack.size() < needle.size()) {
            return -1;
        } else {
            vector<int> pi = getPi(needle);
            int cur = 0, matched = 0;
            while (cur < haystack.size()) {
                if (haystack[cur+matched] == needle[matched]) {
                    matched += 1;

                    if (matched == needle.size()) {
                        return cur;
                    }

                } else {
                    if (matched == 0) {
                        cur += 1;
                    } else {
                        cur += (matched - pi[matched-1]);
                        matched = pi[matched-1];
                    }
                }
            }

            return -1;
        }
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