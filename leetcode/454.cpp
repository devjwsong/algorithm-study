#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int, int> sums;
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                ++sums[nums1[i] + nums2[j]];
            }
        }

        int answer = 0;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                if (sums.find(0 - nums3[i] - nums4[j]) != sums.end()) {
                    answer += sums[0 - nums3[i] - nums4[j]];
                }
            }
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> nums1, nums2, nums3, nums4;
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums1.push_back(val);
    }
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums2.push_back(val);
    }
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums3.push_back(val);
    }
    for (int i=0; i<n; ++i) {
        int val;
        scanf(" %d", &val);
        nums4.push_back(val);
    }

    Solution* sol = new Solution();
    int answer = sol->fourSumCount(nums1, nums2, nums3, nums4);
    printf("%d\n", answer);

    return 0;
}