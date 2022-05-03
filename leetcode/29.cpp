#include <iostream>

using namespace std;


class Solution {
public:
    int UPPERBOUND = 1073741824;

    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == INT32_MIN) return dividend == INT32_MIN ? 1 : 0;

        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = -1;
        }
        int answer = 0;

        if (dividend > 0) dividend = 0 - dividend;
        if (divisor < 0) divisor = 0 - divisor;

        while (dividend + divisor <= 0) {
            int modified = divisor;
            int step = 1;

            while (dividend + modified < 0 && modified < UPPERBOUND) {
                modified = modified << 1;
                step = step << 1;
            }

            if (dividend + modified > 0) {
                modified = modified >> 1;
                step = step >> 1;
            }

            dividend += modified;
            answer -= step;
        }

        if (sign == -1) {
            return answer;
        } else {
            if (answer == INT32_MIN) return INT32_MAX;
            return 0 - answer;
        }
    }
};


int main() {

    int dividend, divisor;
    scanf("%d %d", &dividend, &divisor);

    Solution* sol = new Solution();
    int answer = sol->divide(dividend, divisor);
    printf("%d\n", answer);

    return 0;
}