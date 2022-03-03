#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == target) {
                return left;
            }

            int mid = (left + right) / 2;
            if (mid == left) {
                return -1;
            }
            
            if (nums[left] < nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid;
                } else {
                    left = mid;
                }
            } else {
                if (nums[mid] <= target && target <= nums[right-1]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }

        return -1;
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

    Solution *sol = new Solution();
    int answer = sol->search(nums, target);

    printf("%d\n", answer);

    return 0;
}