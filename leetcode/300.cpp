#include <iostream>
#include <vector>

using namespace std;


// O(n^2)
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, 1);
        dp[0] = 1;

        for (int i=1; i<n; ++i) {
            for (int j=0; j<i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }

        int answer = 1;
        for (int i=0; i<n; ++i) {
            answer = max(answer, dp[i]);
        }

        return answer;
    }
};


// O(nlogn)
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> mem;

        for (int i=0; i<n; ++i) {
            if (mem.size() == 0 || mem[mem.size()-1] < nums[i]) {
                mem.push_back(nums[i]);
            } else {
                int idx = lower_bound(mem.begin(), mem.end(), nums[i]) - mem.begin();
                mem[idx] = nums[i];
            }
        }

        return mem.size();
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

    Solution1* sol1= new Solution1();
    int answer = sol1->lengthOfLIS(nums);
    printf("%d\n", answer);

    Solution2* sol2= new Solution2();
    answer = sol2->lengthOfLIS(nums);
    printf("%d\n", answer);

    return 0;
}