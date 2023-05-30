#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;


// Time: O(n^2)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results(2);
        for (int i=0; i<nums.size(); ++i) {
            for (int j=i+1; j<nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    results[0] = i;
                    results[1] = j;

                    return results;
                }
            }
        }

        return results;
    }
};


// Time: O(nlogn)
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results(2);
        vector< pair<int, int> > pairs(nums.size());

        for (int i=0; i<nums.size(); ++i) {
            pairs[i] = pair<int, int> (nums[i], i);
        }

        sort(pairs.begin(), pairs.end());  // nlogn
        int i = 0, j = pairs.size()-1;
        while (j > i) {  // n
            int sum = pairs[i].first + pairs[j].first;
            if (sum == target) {
                results[0] = pairs[i].second;
                results[1] = pairs[j].second;
                break;
            } else {
                if (sum > target) {
                    --j;
                } else {
                    ++i;
                }
            }
        }

        return results;
    }
};


// Time: O(n)
class Solution3 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for (int i=0; i<n; ++i) {
            int first = nums[i];
            int second = target - first;
            if (mp.find(second) != mp.end()) {
                return {i, mp[second]};
            }
            mp[first] = i;
        }
        
        return {-1, -1};
    }
};
