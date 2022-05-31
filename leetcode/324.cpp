#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Time: O(NlogN), Space: O(N)
// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> answer;
//         sort(nums.begin(), nums.end());

//         int l = (n+1)/2-1;
//         int r = n-1;
//         while (l >= 0 && r >= (n+1)/2) {
//             answer.push_back(nums[l]);
//             --l;
//             answer.push_back(nums[r]);
//             --r;
//         }
//         if (l >= 0) answer.push_back(nums[l]);

//         nums = answer;
//     }
// };


// O(N) time & O(1) space: nth_element(QuickSelect) + 3-way partitioning.
class Solution {
public:
    int idxMod(int n, int idx) {
        if (n % 2 == 0) {
            return (2 * idx + 1) % (n + 1);
        } else {
            return (2 * idx + 1) % n;
        }
    }
    
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        auto midPtr = nums.begin() + n / 2;
        nth_element(nums.begin(), midPtr, nums.end());
        int mid = *midPtr;
        
        int i = 0, j = 0, k = n;
        while (j < k) {
            if (nums[idxMod(n, j)] > mid) {
                swap(nums[idxMod(n, i)], nums[idxMod(n, j)]);
                ++i;
                ++j;
            } else if (nums[idxMod(n, j)] < mid) {
                --k;
                swap(nums[idxMod(n, j)], nums[idxMod(n, k)]);
            } else {
                ++j;
            }
        }
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
    sol->wiggleSort(nums);
    for (int i=0; i<n; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}