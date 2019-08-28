#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> steps;

int memo[301][3]; // 1: 1 stack, 2: 2stack
 
int main() {

    scanf("%d", &N);

    steps.assign(N+1, 0);

    for (int i=1; i<=N; ++i) {
        scanf("%d", &steps[i]);
    }

    memo[1][1] = steps[1];
    memo[2][1] = steps[2];

    for (int i=1; i<=N; ++i) {
        if (i - 1 >= 0) {
            int value = 0;
            for (int j=1; j<2; ++j) {
                value = max(value, memo[i-1][j]);
            }

            memo[i][2] = value + steps[i];
        }

        if (i - 2 >= 0) {
            int value = 0;
            for (int j=1; j<3; ++j) {
                value = max(value, memo[i-2][j]);
            }

            memo[i][1] = value + steps[i];
        }
    }

    printf("%d\n", max(memo[N][1], memo[N][2]));

    return 0;
}