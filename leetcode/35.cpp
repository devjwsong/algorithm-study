#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right  = mid;
            } else {
                left = mid;
            }
        }

        if (nums[right] < target) return right+1;
        if (nums[left] < target) return right;
        return left;
    }
};


int main() {

    int n;
    scanf("%d", &n);
    
    vector<int> nums;
    for (int i=0; i<n; ++i) {
        int num;
        scanf(" %d", &num);
        nums.push_back(num);
    }

    int target;
    scanf("%d", &target);

    Solution *sol = new Solution();
    int answer = sol->searchInsert(nums, target);
    printf("%d\n", answer);

    return 0;
}