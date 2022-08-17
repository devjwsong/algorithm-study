#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 
Dutch National Flag algorithm. 
https://medium.com%2F@medium.com/@shreevatsan/what-is-dutch-national-flag-problem-and-how-is-it-related-to-sorting-e75318fcfefe
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        int mid = 0;
        while (mid <= right) {
            if (nums[mid] == 0) {
                swap(nums[left], nums[mid]);
                ++left;
                ++mid;
            } else if (nums[mid] == 1) {
                ++mid;
            } else if (nums[mid] == 2) {
                swap(nums[mid], nums[right]);
                --right;
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

    Solution *sol = new Solution();
    sol->sortColors(nums);
    for (int i=0; i<nums.size(); ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}