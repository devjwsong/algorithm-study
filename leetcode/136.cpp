#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int state = 0;
        for (int i=0; i<nums.size(); ++i) {
            state = state ^ nums[i];
        }

        return state;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> nums;
    for (int i=0; i<n; ++i) {
        int v;
        scanf(" %d", &v);
        nums.push_back(v);
    }

    Solution *sol = new Solution();
    int answer = sol->singleNumber(nums);

    printf("%d\n", answer);

    return 0;
}