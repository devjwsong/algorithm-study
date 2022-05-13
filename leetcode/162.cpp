#include <iostream>
#include <vector>

using namespace std;


/*
I need to see only mid and mid+1, since the left part will be checked if nums[mid] > nums[mid+1].
Also, since mid is eventually converged to left, left should be the answer index and that's why mid + 1 is assigned to left if mid can never be the answer.
Eventually, in case that left + 1 == right, left == mid and mid + 1 == right
left should be the answer if nums[mid(left)] > nums[mid+1(right)], and right becomes the answer if nums[mid(left)] < nums[mid+1(right)] on the other hand.
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.size() == 2) {
            if (nums[0] > nums[1]) return 0;
            return 1;
        }

        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < nums[mid+1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
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

    Solution* sol = new Solution();
    int answer = sol->findPeakElement(nums);
    printf("%d\n", answer);

    return 0;
}