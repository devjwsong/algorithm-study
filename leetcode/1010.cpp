#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        unordered_map<int, int> mp;
        for (int i=0; i<n; ++i) {
            ++mp[time[i] % 60];
        }

        int res = 0;
        for (int i=0; i<n; ++i) {
            int cur = time[i] % 60;
            --mp[cur];
            if (mp.find((60-cur)%60) != mp.end()) {
                res += mp[(60-cur)%60];
            }
        }

        return res;
    }
};