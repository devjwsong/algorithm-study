#include <iostream>
#include <vector>
#include <climits>

using namespace std;


/*
Binary Search.
1. The objective function is convex.
Obviously, the target value is within the min~max range since if it isn't the total cost cannot be minimum.
And x can be continuous, so the function is also continous.
2. We find the target value using the binary search starting from low=min and high=max.
If f(mid) <= f(mid+1), the optimal point is in the left side.
Otherwise, the optimal point is located in the right side.
3. How do we handle the case that f(mid) = f(mid+1)?
It doesn't matter since this is binary search to find one point among either of them.
If we move our search range into the left half, eventually we will get f(mid).
And we will eventually get to the f(mid+1) if we change the search range into the right half.
Time: O(nlogk). (n: size of array, k: the range of element values.)
Space: O(1).
*/
class Solution {
public:
    long long getCost(vector<int>& nums, vector<int>& cost, int target) {
        int n = nums.size();
        long long res = 0;
        for (int i=0; i<n; ++i) {
            res += ((long long) abs(target-nums[i]) * (long long) cost[i]);
        }

        return res;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        int low = INT_MAX, high = INT_MIN;
        for (int i=0; i<n; ++i) {
            low = min(low, nums[i]);
            high = max(high, nums[i]);
        }

        while (low + 1 < high) {
            int mid = (low + high) / 2;
            long long res0 = getCost(nums, cost, mid);
            long long res1 = getCost(nums, cost, mid+1);

            if (res0 <= res1) {
                high = mid;
            } else {
                low = mid;
            }
        }

        return min(getCost(nums, cost, low), getCost(nums, cost, high));
    }
};
