#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> check;
        for (int i=0; i<nums.size(); ++i) {
            if (check.find(nums[i]) != check.end()) {
                return true;
            }

            check[nums[i]] = true;
        }

        return false;
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
    bool answer = sol->containsDuplicate(nums);
    printf("%d\n", answer);

    return 0;
}