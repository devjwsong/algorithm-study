#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
Custom sorting function.
Time: O(nlogn * logM). (n: the size of array, M: the maximum value.)
Space: O(n * logM).
*/
class Solution {
public:
    static bool compare(string s1, string s2) {
        string cand1 = s1 + s2;
        string cand2 = s2 + s1;

        return cand1 > cand2;
    }

    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> strs (n, "");

        for (int i=0; i<n; ++i) {
            strs[i] = to_string(nums[i]);
        }

        sort(strs.begin(), strs.end(), compare);
        string answer;
        for (int i=0; i<n; ++i) {
            if (answer.size() == 0 && i < n-1 && strs[i] == "0") continue;
            answer += strs[i];
        }
        
        return answer;
    }
};
