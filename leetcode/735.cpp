#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


/*
Stack (or just an array?)
This is a simple simulation problem.
The circumstance when the positive asteroid collides with the negative asteroid is
only when the negative one comes after the previous positive one.
If the negative asteroid has been pushed into the stack already, this one will never collide with the positive asteroid
which will appear later.
So we just iterate the stack and pop the value if it is positive and it has lower absolute value than that of negative one.
In case that the last positive asteroid in the stack has identical size to the size of current negative asteroid,
both asteroids will disappear, which means nothing additional should be pushed.
After that, there is still living negative asteroid, we push it.
Time: O(n).
Space: O(n). 
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> answer;
        for (int i=0; i<n; ++i) {
            if (answer.size() == 0) {
                answer.push_back(asteroids[i]);
            } else {
                if (asteroids[i] > 0) {
                    answer.push_back(asteroids[i]);
                } else {
                    while (!answer.empty() && answer.back() > 0 && answer.back() < abs(asteroids[i])) {
                        answer.pop_back();
                    }
                    if (!answer.empty() && answer.back() == abs(asteroids[i])) {
                        answer.pop_back();
                        continue;
                    }
                    if (answer.empty() || answer.back() < 0) answer.push_back(asteroids[i]);
                }
            }
        }

        return answer;
    }
};
