#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results(2);
        for (int i=0; i<nums.size(); ++i) {
            for (int j=i+1; j<nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    results[0] = i;
                    results[1] = j;

                    return results;
                }
            }
        }

        return results;
    }
};

int main() {

    vector<int> nums;
    int target = 0;

    string input;
    getline(cin, input);
    string cur = "";
    for (int i=0; i<input.size(); ++i) {
        if (input[i] == ' ') {
            nums.push_back(stoi(cur));
            cur = "";
        } else {
            cur += input[i];
        }
    }
    if (cur.size() > 0) {
        nums.push_back(stoi(cur));
    }

    scanf("%d", &target);

    Solution sol;
    vector<int> results = sol.twoSum(nums, target);

    for (int i=0; i<results.size(); ++i) {
        printf("%d ", results[i]);
    }
    printf("\n");

    return 0;
}