#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> answer;
        for (int i=0; i<n; ++i) {
            if (asteroids[i] > 0) {
                answer.push_back(asteroids[i]);
            } else {
                bool isFinished = false;
                while (!answer.empty() && answer.back() > 0 && answer.back() <= abs(asteroids[i]) && !isFinished) {
                    if (answer.back() == abs(asteroids[i])) {
                        isFinished = true;
                    }
                    answer.pop_back();
                }

                if (!answer.empty() && answer.back() > 0) isFinished = true;
                if (!isFinished) answer.push_back(asteroids[i]);
            }
        }

        return answer;
    }
};


int main() {

    int n;
    scanf("%d", &n);

    vector<int> asteroids;
    for (int i=0; i<n; ++i) {
        int val;
        scanf("%d", &val);
        asteroids.push_back(val);
    }

    Solution* sol = new Solution();
    vector<int> answer = sol->asteroidCollision(asteroids);
    for (int i=0; i<answer.size(); ++i) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return 0;
}