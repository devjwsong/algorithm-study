#include <iostream>

using namespace std;

long long dp[90] = {0,};

long long fibonacci(int input) {

    if (input == 0) {
        return dp[0];
    }

    if (input == 1) {
        return dp[1];
    }

    if (dp[input]) {
        return dp[input];
    } else {
        dp[input] = fibonacci(input-1) + fibonacci(input-2);
        return dp[input];
    }

}

int main() {
    int input = 0;
    scanf("%d", &input);

    dp[0] = 0;
    dp[1] = 1;

    long long result = fibonacci(input);

    printf("%lli\n", result);

    return 0;
}