#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;

        for (int i=0; i<n; ++i) {
            if (st.empty() || st.top() * asteroids[i] > 0) {
                st.push(asteroids[i]);
            } else {
                bool isFinished = false;
                while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                    if (abs(st.top()) > abs(asteroids[i])) {
                        isFinished = true;
                        break;
                    } else if (abs(st.top()) == abs(asteroids[i])) {
                        st.pop();
                        isFinished = true;
                        break;
                    } else {
                        st.pop();
                    }
                }
                if (!isFinished) st.push(asteroids[i]);
            }
        }

        vector<int> answer;
        while (!st.empty()) {
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(), answer.end());

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