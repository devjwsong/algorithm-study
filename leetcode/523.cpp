#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
Hash map + Prefix sum.
The idea is using mod.
Since we cannot check all l which makes pSum[j] - pSum[i] = l * k,
we store the prefix sum in modular.
Then if there is same value stored in the hash map at least 2 indices away,
that means the difference between two values can make the multiplication of k.
Time: O(n).
Space: O(k).
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 1) return false;

        unordered_map<int, int> mp;
        int pSum = 0;
        mp[pSum] = 0;
        
        for (int i=0; i<n; ++i) {
            pSum = (pSum + nums[i]) % k;
            if (mp.find(pSum) != mp.end()) {
                if (i - mp[pSum] > 0) return true;
            } else {
                mp[pSum] = i+1;
            }
        }

        return false;
    }
};
