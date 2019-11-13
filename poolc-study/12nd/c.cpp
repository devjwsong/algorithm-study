#include <iostream>

using namespace std;

int N;
int M;

bool memo[31][15001];

void memoization(int i, int w) {
    for (int j=0; j<=500*N; ++j) {
        if (memo[i-1][j]) {
            int value = j;
            memo[i][value] = true;
            memo[i][value+w] = true;
            memo[i][abs(value-w)] = true;
        }
    }
}

int main() {

    scanf("%d", &N);

    for (int i=1; i<=N; ++i) {
        int w;
        scanf("%d", &w);

        memo[i][w] = true;
        memoization(i, w);
    }

    scanf("%d", &M);

    for (int i=1; i<=M; ++i) {
        int m;
        scanf("%d", &m);
        if (m > 500*N) {
            printf("N ");
        } else {
            if (memo[N][m]) {
                printf("Y ");
            } else {
                printf("N ");
            }
        }
    }
    printf("\n");

    return 0;
}