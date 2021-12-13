#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for (int i=1; i<nums.size(); ++i) {
            if (nums[i] > nums[idx]) {
                idx += 1;
                nums[idx] = nums[i];
            }
        }

        if (nums.size() > 0) {
            idx += 1;
        }

        return idx;
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

    Solution *sol = new Solution();
    int result = sol->removeDuplicates(nums);

    printf("%d\n", result);
    for (int i=0; i<nums.size(); ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}