#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<n; ++i) {
            if (i > 0 && nums[i-1] == nums[i]) continue;

            int first = nums[i];
            for (int j=i+1; j<n; ++j) {
                int second = nums[j];

                if (answer.size() > 0 && answer[answer.size()-1][0] == first && answer[answer.size()-1][1] == second) {
                    continue;
                }

                long long newTarget = (long long) target - (long long) first - (long long) second;
                int left = j+1, right = n-1;
                while (left < right) {
                    if (nums[left] + nums[right] > newTarget) {
                        --right;
                    } else if (nums[left] + nums[right] < newTarget) {
                        ++left;
                    } else {
                        answer.push_back({first, second, nums[left], nums[right]});
                        
                        while (left < right && nums[left] == nums[left+1]) {
                            ++left;
                        }
                        while (left < right && nums[right] == nums[right-1]) {
                            --right;
                        }
                        
                        --right;
                        ++left;
                    }
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
        scanf("%d", &val);
        nums.push_back(val);
    }

    int target;
    scanf("%d", &target);

    Solution* sol = new Solution();
    vector<vector<int>> answer = sol->fourSum(nums, target);
    for (int i=0; i<answer.size(); ++i) {
        vector<int> quads = answer[i];
        for (int j=0; j<quads.size(); ++j) {
            printf("%d ", quads[j]);
        }
        printf("\n");
    }

    return 0;
}