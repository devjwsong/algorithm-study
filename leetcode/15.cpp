#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        if (nums.size() < 3) {
            return answer;
        }

        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int min = nums[i];
            int left = i+1, right = nums.size()-1;
            int prevDiff = -1;

            while(left < right) {
                int curSum = min + nums[left] + nums[right];
                if (curSum == 0) {
                    if (nums[right] - nums[left] != prevDiff) {
                        answer.push_back(vector<int> {min, nums[left], nums[right]});
                        prevDiff = nums[right] - nums[left];
                    }
                    
                    ++left;
                    --right;
                } else if (curSum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
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

    Solution *sol = new Solution();
    vector<vector<int>> answer = sol->threeSum(nums);

    for (int i=0; i<answer.size(); ++i) {
        for (int j=0; j<answer[i].size(); ++j) {
            printf("%d ", answer[i][j]);
        }
        printf("\n");
    }

    return 0;
}