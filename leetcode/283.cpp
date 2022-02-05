#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i] != 0) {
                int temp = nums[i];
                nums[i] = nums[idx];
                nums[idx] = temp;
                ++idx; 
            }
        }

        for (int i=0; i<nums.size(); ++i) {
            printf("%d ", nums[i]);
        }
        printf("\n");
    }
};


int main() {

    int num;
    scanf("%d", &num);

    vector<int> nums;
    for (int i=0; i<num; ++i) {
        int val;
        scanf(" %d", &val);
        nums.push_back(val);
    }

    Solution *sol = new Solution();
    sol->moveZeroes(nums);

    return 0;
}