#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
Binary Search + Two pointers.
Time: O(nlogn)
Space: O(1)
Simple but not quite easy to implement.
Basically, we conduct the binary search to find the kth difference from 0(minimum) to nums[n-1]-nums[0](maximum).
In each iteration, we find how many differences are smaller than mid.
To calculate this, we use two pointers which represent for two elements in each pair.
Starting with (i,j)=(0,1), extending the range makes the difference larger.
So by increasing j as much as possible, we can find the number of smaller values 
in the condiction of a certain fixed i.
After reaching the maximum j(let's say m), increase i so that we can search for another range.
With the bigger index m, we don't have to check the rest of is which are smaller than current i,
since obviously they are larger than mid.
So i and j iterates the array once, then the time complexity becomes O(n).
*/
class Solution {
public:
    int countSmaller(vector<int>& nums, int mid) {
        int n = nums.size();
        int i = 0, j = 1;
        int res = 0;
        while (i < n-1) {
            while (j < n && nums[j] - nums[i] < mid) {
                ++j;
            }
            res += (j - i - 1);
            ++i;
        }

        return res;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 2) return abs(nums[0]-nums[1]);

        sort(nums.begin(), nums.end());
        int left = 0, right = nums[n-1] - nums[0];
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            int count = countSmaller(nums, mid);
            if (count >= k) {
                right = mid;
            } else {
                left = mid;
            }
        }

        if (countSmaller(nums, right) < k) return right;
        return left;
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

    int k;
    scanf("%d", &k);

    Solution* sol = new Solution();
    int answer = sol->smallestDistancePair(nums, k);
    printf("%d\n", answer);

    return 0;
}