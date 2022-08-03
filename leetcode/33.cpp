#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > target) {
                if (target > nums[left]) {
                    right = mid;
                } else if (target < nums[left]) {
                    if (nums[mid] > nums[right]) {
                        left = mid;
                    } else {
                        right = mid;
                    }
                } else {
                    return left;
                }
            } else if (nums[mid] < target) {
                if (nums[mid] > nums[left]) {
                    left = mid;
                } else {
                    if (target > nums[right]) {
                        right = mid;
                    } else if (target < nums[right]) {
                        left = mid;
                    } else {
                        return right;
                    }
                }
            } else {
                return mid;
            }
        }   

        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
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