#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0, end = nums.size();
        while(start+1 < end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] > target) {
                end = mid;
            } else {
                start = mid;
            }
        }

        if (nums[start] >= target) {
            return start;
        } else {
            return start+1;
        }
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