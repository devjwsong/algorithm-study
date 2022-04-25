#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> sum2num;

        int sum = 0, answer = 0;
        sum2num[0] = 1;
        for (int i=0; i<n; ++i) {
            sum += nums[i];
            int needed = sum - k;
            if (sum2num.find(needed) != sum2num.end()) {
                answer += sum2num[needed];
            }
            sum2num[sum]++;
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

    int k;
    scanf("%d", &k);

    Solution* sol = new Solution();
    int answer = sol->subarraySum(nums, k);
    printf("%d\n", answer);

    return 0;
}