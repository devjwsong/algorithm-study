#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    static bool compare(string s1, string s2) {
        return s1 + s2 > s2 + s1;
    }

    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        bool allZeros = true;
        for (int i=0; i<n; ++i) {
            if (nums[i] != 0) {
                allZeros = false;
                break;
            }
        }
        if (allZeros) return "0";

        vector<string> strs;
        for (int i=0; i<n; ++i) {
            strs.push_back(to_string(nums[i]));
        }
        sort(strs.begin(), strs.end(), compare);

        string answer = "";
        for (int i=0; i<n; ++i) {
            answer += strs[i];
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> nums;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums.push_back(val);
    }

    Solution* sol = new Solution();
    string answer = sol->largestNumber(nums);
    cout<<answer<<"\n";

    return 0;
}