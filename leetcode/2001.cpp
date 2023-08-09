#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
Hash map.
Be careful not to count the same pair repeartedly.
Time: O(n).
Space: O(n).
*/
class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, int> mp;
        long long answer = 0;
        int n = rectangles.size();
        for (int i=0; i<n; ++i) {
            double ratio = (double) rectangles[i][0] / (double) rectangles[i][1];
            if (mp.find(ratio) != mp.end()) {
                answer += mp[ratio];
            }
            ++mp[ratio];
        }

        return answer;
    }
};
