#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[left]) {
                if (nums[mid] > nums[right]) {
                    left = mid;
                } else {
                    right = mid;
                }
            } else {
                right = mid;
            }
        }

        return min(nums[left], nums[right]);
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