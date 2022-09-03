#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            
            if (nums[mid] > target) {
                if (target > nums[left]) {
                    right = mid;
                } else if (target < nums[left]) {
                    if (nums[mid] > nums[left]) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                } else {
                    return left;
                }
            } else {
                if (target < nums[right]) {
                    left = mid;
                } else if (target > nums[right]) {
                    if (nums[mid] > nums[left]) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                } else {
                    return right;
                }
            }
        }
    
        if (nums[right] == target) return right;
        if (nums[left] == target) return left;
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