#include <iostream>
#include <vector>

using namespace std;


/*
1. Reducing the lenght in the flat case. Reducing both side makes the array converged into strictly increasing condition.
2. I should check what half array contains the target & mid.
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int left = 0, right = n-1;
        while(left + 1 < right) {
            int mid = (left + right) / 2;

            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                ++left;
                --right;
            } else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && nums[mid] > target) {
                    right = mid;
                } else {
                    left = mid;
                }
            } else {
                if (nums[right] >= target && nums[mid] < target) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
        }
        
        if (nums[left] == target || nums[right] == target) return true;
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

    int target;
    scanf("%d", &target);

    Solution* sol = new Solution();
    bool answer = sol->search(nums, target);
    printf("%d\n", answer);

    return 0;
}