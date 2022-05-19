#include <iostream>

using namespace std;


class Solution {
public:
    int count(int n, int k) {
        int res = 0;
        int cur = k;
        while (cur <= n) {
            res += (n / cur);
            cur *= k;
        }

        return res;
    }

    int trailingZeroes(int n) {
        return min(count(n, 2), count(n, 5));
    }
};


int main() {

    int n;
    scanf("%d", &n);

    Solution* sol = new Solution();
    int answer = sol->trailingZeroes(n);
    printf("%d\n", answer);

    return 0;
}