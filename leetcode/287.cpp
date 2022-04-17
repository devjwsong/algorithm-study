#include <iostream>
#include <vector>

using namespace std;

// 1. Negative indexing: O(N) time & O(1) space.
class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for (int i=0; i<n; ++i) {
            int val = abs(nums[i]);
            if (nums[val-1] < 0) return abs(nums[i]);

            nums[val-1] *= -1;
        }

        return -1;
    }
};


// 2. Binary search: O(NlogN) time & O(1) space.
class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n-1;

        while(low <= high) {
            int mid = (low + high) / 2;
            int count = 0;
            for (int i=0; i<n; ++i) {
                if (nums[i] <= mid) {
                    ++count;
                }
            }

            if (count > mid) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return low;
    }
};


// 3. Floyd's tortoise & hare: O(N) time & O(1) space.
class Solution3 {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        int slow = nums[0];
        int fast = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);
    
        fast = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
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

    // Solution1* sol1 = new Solution1();
    // int answer = sol1->findDuplicate(nums);
    // printf("%d\n", answer);

    // Solution2* sol2 = new Solution2();
    // int answer = sol2->findDuplicate(nums);
    // printf("%d\n", answer);

    // Solution3* sol3 = new Solution3();
    // int answer = sol3->findDuplicate(nums);
    // printf("%d\n", answer);

    return 0;
}