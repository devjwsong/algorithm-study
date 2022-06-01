#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


/*
Next permutation always makes the certain right part of the array sorted in descending order.
So, first find the previous element before the descending part begins.
If start == -1, this means the array is the last state, so simply reversing makes the array the original state.
If start != -1, then this start point should be integrated to the right part after next permutation.
So, find the first larger value than start, which should be moved to the next start position.
The descending part is still sorted after the swap, which is obvious.
Then reverse the descending part to start over again.
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int start = -1;
        for (int i=nums.size()-2; i>=0; --i) {
            if (nums[i] < nums[i+1]) {
                start = i;
                break;
            }
        }

        if (start != -1) {
            for (int i=nums.size()-1; i>=0; --i) {
                if (nums[i] > nums[start]) {
                    swap(nums[i], nums[start]);
                    break;
                }
            }
        }
        
        reverse(nums.begin() + start + 1, nums.end());
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
    sol->nextPermutation(nums);

    for (int i=0; i<n; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}