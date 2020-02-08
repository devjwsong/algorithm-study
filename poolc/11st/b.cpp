#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> houses;

int memo[1001][3];

int main() {

    scanf("%d", &N);

    houses.assign(N+1, vector<int> {0, 0, 0});

    for (int i=1; i<=N; ++i) {
        int r, g, b;
        scanf("%d %d %d", &r, &g, &b);

        houses[i][0] = r;
        houses[i][1] = g;
        houses[i][2] = b;
    }

    for (int i=1; i<=N; ++i) {
        for (int j=0; j<3; ++j) {
            if (j == 0) {
                memo[i][j] = min(memo[i-1][1], memo[i-1][2]) + houses[i][j];
            } else if (j == 1) {
                memo[i][j] = min(memo[i-1][0], memo[i-1][2]) + houses[i][j];
            } else if (j == 2) {
                memo[i][j] = min(memo[i-1][0], memo[i-1][1]) + houses[i][j];
            }
        }
    }    

    int answer = min(memo[N][0], min(memo[N][1], memo[N][2]));

    printf("%d\n", answer);

    return 0;
}