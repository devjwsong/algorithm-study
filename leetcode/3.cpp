#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
A hash map is used to memorize the last index of each character.
Now s[left:right] is the current substring and right indicates the current index.
If s[right] exists in the hash map, then we should shrink the substring.
The point here is if current left > mp[s[right]]+1, then left should be kept the same.
For example, if the input is "abba" and if right = 3,
then mp['a'] = 0 made the left = 1, which is not what we want.
So left should be kept as a lowerbound of the sub string.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = s.size();
        if (n == 0) return 0;
        
        int left = 0, right = 0;
        int answer = 0;
        while (right < n) {
            if (mp.find(s[right]) != mp.end()) {
                left = max(left, mp[s[right]] + 1);
            }
            mp[s[right]] = right;
            answer = max(answer, right-left+1);
            ++right;
        }
        
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