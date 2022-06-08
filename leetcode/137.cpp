#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int answer = 0;
        for (int b=0; b<32; ++b) {
            int sum = 0;
            for (int i=0; i<n; ++i) {
                if (nums[i] & (1 << b)) {
                    ++sum;
                }
            }
            if (sum % 3 != 0) {
                answer |= (1 << b);
            }
        }

        return answer;
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
    int answer = sol->singleNumber(nums);
    printf("%d\n", answer);

    return 0;
}