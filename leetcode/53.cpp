#include <iostream>
#include <vector>

using namespace std;

// Dynamic Programming
class Solution1 {
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

// Divide & Conquer
class Solution2 {
    public:
        int findMidsum(vector<int>& nums, int start, int end, int mid) {
            int leftSum = -10000;
            int sum = 0;
            for (int i=mid-1; i>=start; --i) {
                sum += nums[i];
                leftSum = max(leftSum, sum);
            }

            int rightSum = -10000;
            sum = 0;
            for (int i=mid; i<end; ++i) {
                sum += nums[i];
                rightSum = max(rightSum, sum);
            }
            
            return max(max(leftSum, rightSum), leftSum + rightSum);
        }

        int findSum(vector<int>& nums, int start, int end) {
            if (start + 1 == end) {
                return nums[start];
            }

            int mid = (start + end) / 2;

            int leftSum = findSum(nums, start, mid);
            int rightSum = findSum(nums, mid, end);
            int midSum = findMidsum(nums, start, end, mid);

            return max(max(leftSum, rightSum), midSum);
        }

        int maxSubArray(vector<int>& nums) {
            return findSum(nums, 0, nums.size());
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

    Solution1 *sol1 = new Solution1();
    int answer = sol1->maxSubArray(nums);
    printf("%d\n", answer);

    Solution2 *sol2 = new Solution2();
    answer = sol2->maxSubArray(nums);
    printf("%d\n", answer);

    return 0;
}