#include <iostream>
#include <vector>

using namespace std;


/*
Binary Search.
The point here is to make sure considering all possible cases.
Think about how left, right, target, mid can be aligned.
L T M | R => right = mid.
L T M R => right = mid.
L T | M R => right = mid.
L M T R => left = mid.
L M | T R => left = mid.
L M T | R => left = mid.
L | M T R => left = mid.
L | T M R => right mid.
Time: O(logn).
Space: O(1).
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;

            if (nums[mid] > target) {
                if (nums[mid] < nums[right]) {
                    right = mid;
                } else {
                    if (nums[left] <= target) {
                        right = mid;
                    } else {
                        left = mid;
                    }
                }
            } else if (nums[mid] < target) {
                if (nums[left] < nums[mid]) {
                    left = mid;
                } else {
                    if (target <= nums[right]) {
                        left = mid;
                    } else {
                        right = mid;
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
