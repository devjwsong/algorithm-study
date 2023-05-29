#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
Prefix sum + Hash map.
Simple number theory.
Since all subarrays should be contiguous, they can be represented as subtraction of two prefix sums.
(b - a) % k == 0 => b % k == a % k.
Therefore, we need to track the hash map and calculate the possible combinations from the prefix sums which have same remainders.
Time: O(n).
Space: O(n).
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pSums (n, 0);
        pSums[0] = nums[0];
        for (int i=1; i<n; ++i) {
            pSums[i] = pSums[i-1] + nums[i];
        }

        unordered_map<int, int> mp;
        for (int i=0; i<n; ++i) {
            if (pSums[i] % k < 0) {
                ++mp[pSums[i] % k + k];
            } else {
                ++mp[pSums[i] % k];
            }
        }

        int res = 0;
        for (unordered_map<int, int>::iterator i=mp.begin(); i != mp.end(); ++i) {
            if (i->first == 0) res += i->second;
            if (i->second > 1) {
                res += (i->second * (i->second-1) / 2);
            }
        }

        return res;
    }
};
