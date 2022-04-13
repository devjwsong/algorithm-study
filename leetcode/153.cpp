#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while (left < right) {
            if (nums[left] < nums[right]) {
                return nums[left];
            }

            int mid = (left + right) / 2;
            if (left + 1 == mid && mid + 1 == right) return min(nums[right], nums[mid]);
            if (left == mid) return min(nums[left], nums[right]);

            if (nums[left] < nums[mid]) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return nums[left];
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
    int answer = sol->findMin(nums);
    printf("%d\n", answer);

    return 0;
}