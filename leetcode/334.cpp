#include <iostream>
#include <vector>

using namespace std;


// Time: O(n), Space: O(n)
class Solution1 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        vector<int> leftMins (n, INT32_MAX);
        vector<int> rightMaxs (n, INT32_MIN);
        for (int i=1; i<n; ++i) {
            leftMins[i] = min(leftMins[i-1], nums[i-1]);
        }
        for (int i=n-2; i>=0; --i) {
            rightMaxs[i] = max(rightMaxs[i+1], nums[i+1]);
        }

        for (int i=1; i<n-1; ++i) {
            if (leftMins[i] < nums[i] && nums[i] < rightMaxs[i]) return true;
        }

        return false;
    }
};


/*
Time: O(n), Space: O(1)
Left should contain the smallest element and mid should contain the element which is larger than left.
First, left and mid is set to MAX.
While iterating & fixing right, update left or mid.
If right <= left, then left should be updated since it is the smallest value till right.
If left < right <= mid, then mid should be updated since it is the smallest but larger value than left till right.
If left < mid < right, this is the case we want to find, so return true.
If left is the smallest value, and the mid is second smallest value at the some fixed point right,
there is no answer if left < mid < right is not satisfied, since that means mid >= right, and larger mid does not make any difference.
Also, if either left or mid is not updated, which means that there is no combination which satisfies left < mid, there is no answer triplet.
Finally, the reason why '=' is included is that we want to update left and mid when they are strictly different.
If the condition is either "right < left" or "right < mid", when all elements are the same, for instance "1 1 1 1 1 1",
the third condition is satisfied and the algorithm will return true, which is wrong.
*/
class Solution2 {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int left = INT32_MAX, mid = INT32_MAX;
        for (int i=0; i<n; ++i) {
            int right = nums[i];
            if (right <= left) {
                left = right;
            } else if (right <= mid) {
                mid = right;
            } else {
                return true;
            }
        }

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

    Solution1* sol1 = new Solution1();
    bool answer = sol1->increasingTriplet(nums);
    printf("%d\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->increasingTriplet(nums);
    printf("%d\n", answer);

    return 0;
}