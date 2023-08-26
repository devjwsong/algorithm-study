#include <iostream>
#include <vector>

using namespace std;


/*
Simple math.
Note that there is only one down move for robots.
So there are n possible routes the robot1 can take.
And for every route by the robot1, there should be two possible sequences which survives fromf the route: top and down,
which are separated by the vertical move conducted by the robot1.
So in order to maximize the cost, the robot2 should take larger value between two.
There is no point of taking other routes since it will get unnecessary and unoptimal 0 value.
Time: O(n).
Space: O(1).
*/
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long topSum = 0, downSum = 0;
        for (int c=1; c<n; ++c) {
            topSum += grid[0][c];
        }
        long long answer = topSum;
        for (int c=1; c<n; ++c) {
            topSum -= grid[0][c];
            downSum += grid[1][c-1];
            answer = min(answer, max(topSum, downSum));
        }

        return answer;
    }
};
