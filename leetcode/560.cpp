#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
Prefix sum + Hash map.
We store the number of each sum in the hash map and for each iteration, we find the target
which can make the k with target - sums[i] = k.
Make sure that we don't count repetitively, for example the value we are considering right now.
So we need to erase it after processed.
Time: O(n).
Space: O(n).
*/
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums (n+1, 0);
        for (int i=0; i<n; ++i) {
            sums[i+1] = sums[i] + nums[i];
        }

        unordered_map<int, int> mp;
        for (int i=0; i<=n; ++i) {
            ++mp[sums[i]];
        }

        int answer = 0;
        for (int i=0; i<=n; ++i) {
            --mp[sums[i]];
            if (mp[sums[i]] == 0) mp.erase(sums[i]);

            int target = k + sums[i];
            if (mp.find(target) != mp.end()) {
                answer += mp[target];
            }
        }

        return answer;
    }
};


/*
Same approach, but more efficient.
We don't need additional prefix sum list
since while iterating, we can calculate the sum so far and store it.
Then we can refer to the map and there is no repetition issue
because the map only has the sums which have appeared before the current index.
Time: O(n).
Space: O(n).
*/
class Solution2 {
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
