#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
The idea is based on a greedy algorithm, which include as many non-overlapping minimum valid substring as possible.
Time: O(n)
Space: O(n)
*/
class Solution {
public:
    /*
    This function extend the right bound so that we can include all letters inside the substrings.
    If this is not possible, return -1.
    And this part is not O(n^2) even if it seems,
    because there are only 26 valid substring possible.
    Therefore, outer loop runs maximum 26 times.
    */
    int check(string& s, int i, unordered_map<char, pair<int, int>>& char2Range) {
        int start = char2Range[s[i]].first, end = char2Range[s[i]].second;
        for (int j=start; j<=end; ++j) {
            if (char2Range.find(s[j]) != char2Range.end() && char2Range[s[j]].first < i) return -1;
            end = max(end, char2Range[s[j]].second);
        }

        return end;
    }

    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        unordered_map<char, pair<int, int>> char2Range;
        for (int i=0; i<n; ++i) {
            if (char2Range.find(s[i]) == char2Range.end()) {
                char2Range[s[i]] = {i, i};
            } else {
                char2Range[s[i]].second = i;
            }
        }

        vector<string> answer;
        int right = -1;
        for (int i=0; i<n; ++i) {
            char c = s[i];
            if (char2Range.find(c) != char2Range.end()) {
                if (i == char2Range[c].first) {
                    int newRight = check(s, i, char2Range);

                    /*
                    If newRight != -1, that means we can have a valid substring starting from index i.
                    If current substring is not overlapped with right, then first make a dummy string.
                    Then right is updated into a new value.
                    answer.back() is the last recent valid substring.
                    If there is a shorter valid substring within the current right range,
                    it is updated into the shorter one.
                    */
                    if (newRight != -1) {
                        if (i > right) answer.push_back("");
                        right = newRight;
                        answer.back() = s.substr(i, right-i+1);
                    }
                }
            }
        }

        return answer;
    }
};


int main() {

    string s;
    getline(cin, s);

    Solution* sol = new Solution();
    vector<string> answer = sol->maxNumOfSubstrings(s);
    for (int i=0; i<answer.size(); ++i) {
        cout<<answer[i]<<" ";
    }
    cout<<endl;

    return 0;
}