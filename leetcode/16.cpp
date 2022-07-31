#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int answer = 0, diff = INT32_MAX;
        for (int i=0; i<n-2; ++i) {
            int min = nums[i];

            int left = i+1, right = n-1;
            int sum = 0;
            while (left + 1 < right) {
                sum = min + nums[left] + nums[right];
                if (sum > target) {
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    return target;
                }
            }

            sum = min + nums[left] + nums[right];
            if (abs(sum - target) < diff) {
                answer = sum;
                diff = abs(sum-target);
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

    int target;
    scanf("%d", &target);

    Solution* sol = new Solution();
    int answer = sol->threeSumClosest(nums, target);
    printf("%d\n", answer);

    return 0;
}