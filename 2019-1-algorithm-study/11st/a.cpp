#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> mats;

long long memo[501][501];

int main() {

    scanf("%d", &N);

    mats.assign(N+1, {0, 0});

    for (int i=1; i<=N; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        mats[i] = {a, b};
    }

    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            if (i==j) {
                memo[i][j] = 0;
            } else {
                memo[i][j] = INT_MAX;
            }
        }
    }
    
    for (int d=1; d<=N-1; ++d) {
        for (int i=1; i<=(N-d); ++i) {
            for (int j=i; j<=i+d; ++j) {
                memo[i][i+d] = min(memo[i][i+d], memo[i][j] + memo[j+1][i+d] + mats[i].first * mats[j].second * mats[i+d].second);
            }
        }
    }

    printf("%lld\n", memo[1][N]);

    return 0;
}