#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


/*
Hash map + Simple trick.
The point here is counting the maximum number of edges using the hash map.
Then the number of bricks which the vertical line goes through is the number of rows - the number of edges.
The edge case is that there is no edges, so we just return the number of rows.
Time: O(n * m). (n: # of rows, m: the maximum number of bricks in each row.)
=> n * m itself can be maximum 10^8, but the total number of brick is bounded by 2 * 10^4.
Space: O(m).
*/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        int n = wall.size();
        int width = 0;
        for (int j=0; j<wall[0].size(); ++j) {
            width += wall[0][j];
        }

        int maxNumEdges = 0;
        for (int i=0; i<n; ++i) {
            int cur = 0;
            for (int j=0; j<wall[i].size(); ++j) {
                cur += wall[i][j];
                if (cur < width) {
                    ++mp[cur];
                    maxNumEdges = max(maxNumEdges, mp[cur]);
                }
            }
        }

        return n - maxNumEdges;
    }
};
