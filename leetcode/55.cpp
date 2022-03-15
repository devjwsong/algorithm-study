#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i=0; i<n; ++i) {
            if (farthest < i) {
                return false;
            }

            farthest = max(farthest, i + nums[i]);
        }

        return true;
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
    bool answer = sol->canJump(nums);
    printf("%d\n", answer);

    return 0;
}