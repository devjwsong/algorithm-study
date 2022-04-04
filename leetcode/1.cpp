#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution1 {
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

class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results(2);
        vector< pair<int, int> > pairs(nums.size());

        for (int i=0; i<nums.size(); ++i) {
            pairs[i] = pair<int, int> (nums[i], i);
        }

        sort(pairs.begin(), pairs.end());  // nlogn
        int i = 0, j = pairs.size()-1;
        while (j > i) {  // n
            int sum = pairs[i].first + pairs[j].first;
            if (sum == target) {
                results[0] = pairs[i].second;
                results[1] = pairs[j].second;
                break;
            } else {
                if (sum > target) {
                    --j;
                } else {
                    ++i;
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

    Solution1 sol1;
    vector<int> results = sol1.twoSum(nums, target);

    for (int i=0; i<results.size(); ++i) {
        printf("%d ", results[i]);
    }
    printf("\n");

    Solution2 sol2;
    results = sol2.twoSum(nums, target);

    for (int i=0; i<results.size(); ++i) {
        printf("%d ", results[i]);
    }
    printf("\n");

    return 0;
}