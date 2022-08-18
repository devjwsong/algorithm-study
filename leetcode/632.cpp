#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;


/*
Priority Queue.
Time: O(KN*log(KN))
Space: O(KN)
The idea is to keep the number of elements in the heap as the same as k, 
so that at least one element from each array can be included.
*/
class Solution1 {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int low = -1e5, high = 1e5;
        int maxVal = INT32_MIN;

        for (int i=0; i<k; ++i) {
            maxVal = max(maxVal, nums[i][0]);
            pq.push({nums[i][0], 0, i});
        }

        while (pq.size() == k) {
            vector<int> cur = pq.top();
            pq.pop();

            int minVal = cur[0], j = cur[1], i = cur[2];
            if (high - low > maxVal - minVal) {
                high = maxVal;
                low = minVal;
            }
            
            if (j+1 < nums[i].size()) {
                maxVal = max(maxVal, nums[i][j+1]);
                pq.push({nums[i][j+1], j+1, i});
            }
        }

        return {low, high};
    }
};


/*
Hash map + Sliding window.
Time: O(KN*log(KN))
Space: O(KN)
Confusing but much more optimized solution.
The idea is to keep the window containing at least one element from each array.
And this greedy approach works, since if current window satisfies the condition,
moving left only makes the range smaller.
And the window gets to violate the condition, then moving right again finds another next window
which satisfies the condition naturally.
*/
class Solution2 {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<pair<int, int>> merged;
        for (int i=0; i<k; ++i) {
            for (int j=0; j<nums[i].size(); ++j) {
                merged.push_back({nums[i][j], i});
            }
        }
        sort(merged.begin(), merged.end());

        int low = -1e5, high = 1e5;
        int count = k, left = 0;
        unordered_map<int, int> mp;
        for (int right=0; right < merged.size(); ++right) {
            int i = merged[right].second, val = merged[right].first;
            if (mp[i] == 0) {
                --count;
            }
            ++mp[i];

            while(count == 0) {
                if (merged[right].first - merged[left].first < high - low) {
                    high = merged[right].first;
                    low = merged[left].first;
                }

                --mp[merged[left].second];
                if (mp[merged[left].second] == 0) ++count;
                ++left;
            }
        }

        return {low, high};
    }
};


int main() {

    int k;
    scanf("%d", &k);

    vector<vector<int>> nums;
    for (int i=0; i<k; ++i) {
        vector<int> v;
        int n;
        scanf("%d", &n);

        for (int j=0; j<n; ++j) {
            int val;
            scanf("%d", &val);
            v.push_back(val);
        }

        nums.push_back(v);
    }

    Solution1* sol1 = new Solution1();
    vector<int> answer = sol1->smallestRange(nums);
    printf("%d %d\n", answer[0], answer[1]);

    Solution2* sol2 = new Solution2();
    answer = sol2->smallestRange(nums);
    printf("%d %d\n", answer[0], answer[1]);

    return 0;
}