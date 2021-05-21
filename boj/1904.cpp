#include <iostream>

using namespace std;

int N;
int memo[1000001];

int main() {

    scanf("%d", &N);

    memo[1] = 1;
    memo[2] = 2;

    for (int i=3; i<=N; ++i) {
        memo[i] = (memo[i-1] + memo[i-2]) % 15746;
    }

    printf("%d\n", memo[N]);

    return 0;
}