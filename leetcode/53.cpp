#include <iostream>
#include <vector>

using namespace std;

// Dynamic Programming
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum[nums.size()];  
        sum[0] = nums[0];

        for (int i=1; i<nums.size(); ++i) {
            sum[i] = max(nums[i], sum[i-1] + nums[i]);
        }

        int answer = -10000;
        for (int i=0; i<nums.size(); ++i) {
            answer = max(answer, sum[i]);
        }

        return answer;
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

    Solution *sol = new Solution();
    int answer = sol->maxSubArray(nums);
    printf("%d\n", answer);

    return 0;
}