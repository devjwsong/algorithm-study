#include <iostream>

using namespace std;

int dp[45] = {0,};

int fibonacci(int input) {

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

    int result = fibonacci(input);

    printf("%d\n", result);

    return 0;
}