#include <iostream>
#include <vector>

using namespace std;


/*
Binary Search.
The point here is each time we should check the maximum value can be adjusted into mid.
Since the rule is sending the value from right to left, we count the number of available moves.
Time: O(nlogv).
Space: O(1).
*/
class Solution1 {
public:
    bool isAdjustable(vector<int>& nums, int target) {
        int n = nums.size();
        if (nums[0] > target) return false;

        long long count = 0;
        for (int i=0; i<n; ++i) {
            if (nums[i] <= target) {
                count += (target - nums[i]);
            } else {
                if (count < nums[i] - target) return false;
                count -= (nums[i] - target);
            }
        }

        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int high = 0;
        for (int i=0; i<n; ++i) {
            high = max(high, nums[i]);
        }

        if (high == 0) return 0;
        int low = 0;
        while (low + 1 < high) {
            int mid = (low + high) / 2;
            if (isAdjustable(nums, mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }

        if (isAdjustable(nums, low)) return low;
        return high;
    }
};


/*
Greedy.
First of all, the rule can be seen as adjusting the maximum values closer to the overall average.
So every time we consider a new value, we re-calculate the average.
However, we cannot always decrease the maximum when the new value is not large enough, we cannot pass the value to left.
So we take the maximum and this is important because we always take the worst case sceniaro for minimum maximum value.
And if the sum cannot be divided into the number of values exactly, we should add 1 because we cannot decrease the value completely.
Time: O(n).
Space: O(1).
*/
class Solution2 {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        long long answer = nums[0], sum = nums[0];
        for (int i=1; i<n; ++i) {
            sum += nums[i];
            answer = max(answer, sum / (i+1) + (sum % (i+1) > 0));
        }

        return answer;
    }
};
