#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int p[46];
        p[0] = 0;
        p[1] = 1;
        p[2] = 2;

        for (int i=3; i<=n; ++i) {
            p[i] = p[i-1] + p[i-2];
        }

        return p[n];
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution *sol = new Solution();
    int answer = sol->climbStairs(n);

    printf("%d\n", answer);

    return 0;
}
