#include <iostream>
#include <unordered_map>

using namespace std;

// Memoization
class Solution1 {
public:
    unordered_map<int, double> dp;
    double cal(double x, int cur) {
        if (dp.find(cur) != dp.end()) return dp[cur];

        double val = cal(x, cur/2) * cal(x, cur-cur/2);
        dp[cur] = val;

        return val;
    }

    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n == -1) return 1.0/x;
        if (x == 0.0) return x;

        bool isLimit = false;
        if (n == INT32_MIN) {
            isLimit = true;
            n = INT32_MAX;
        }

        bool positive = true;
        if (n < 0) {
            positive = false;
            n = -n;
        }

        dp[0] = 1.0;
        dp[1] = x;

        double answer = cal(x, n);

        if (isLimit) {
            return 1.0/answer * 1.0/x;
        }

        if (!positive) return 1.0/answer;
        return answer;
    }
};


// Binary exponentation
class Solution2 {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n == 1) return x;
        if (n == -1) return 1.0/x;
        if (x == 0.0) return x;

        long nn = n;
        if (nn < 0) nn = -1 * nn;

        double answer = 1.0;
        while(nn > 0) {
            if (nn % 2 == 0) {
                x *= x;
                nn >>= 1;
            } else {
                answer *= x;
                --nn;
            }
        }

        if (n < 0) return 1.0/answer;
        return answer;
    }
};


int main() {

    double x;
    int n;
    scanf("%lf %d", &x, &n);

    Solution1* sol1 = new Solution1();
    double answer = sol1->myPow(x, n);
    printf("%lf\n", answer);

    Solution2* sol2 = new Solution2();
    answer = sol2->myPow(x, n);
    printf("%lf\n", answer);

    return 0;
}