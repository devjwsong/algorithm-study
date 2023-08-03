#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


/*
Hash map.
The point here is the length of target palindromes is set to 3.
So the problem can be simplified as finding the number of unique characters which can be located between two identical characters.
For that, we pre-calculate the left-most & right-most index of each alphabet.
The rest of things are counting the unique characters between two indices.
Time: O(26 * n).
Space: O(26 * 26).
*/
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<pair<int, int>> idxs (26, {-1, -1});
        for (int i=0; i<n; ++i) {
            if (idxs[s[i]-'a'].first == -1) {
                idxs[s[i]-'a'].first = i;
            } else {
                idxs[s[i]-'a'].second = i;
            }
        }

        int answer = 0;
        for (char c='a'; c<='z'; ++c) {
            int left = idxs[c-'a'].first, right = idxs[c-'a'].second;
            if (left != -1 && right != -1 && right > left) {
                unordered_set<char> st;
                for (int i=left+1; i<right; ++i) {
                    st.insert(s[i]);
                }
                answer += st.size();
            }
        }

        return answer;
    }
};
