#include <iostream>

using namespace std;

int N, K;
long long memo[1001][1001];

int main() {

    scanf("%d %d", &N, &K);

    for (int i=1; i<=N; ++i) {
        for (int j=0; j<=i; ++j) {
            if (j == 0) {
                memo[i][j] = 1;
            } else if (i == j) {
                memo[i][j] = 1;
            } else {
                memo[i][j] = (memo[i-1][j-1] + memo[i-1][j]) % 10007;
            }
        }
    }

    printf("%lld\n", memo[N][K]);

    return 0;
}