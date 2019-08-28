#include <iostream>
#include <vector>

using namespace std;

int T;
int n;

int memo[100000][2];

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        scanf("%d", &n);

        for (int r=0; r<2; ++r) {
            for (int c=0; c<n; ++c) {
                int p;
                scanf("%d", &p);

                memo[c][r] = p;
            }
        }

        memo[1][0] = max(memo[1][0], memo[0][1]+memo[1][0]);
        memo[1][1] = max(memo[1][1], memo[0][0]+memo[1][1]);

        int idx = 0;
        int max_value = max(memo[idx][0], memo[idx][1]);
        
        for (int i=2; i<n; ++i) {
            memo[i][0] = max(memo[i-1][1]+memo[i][0], max_value+memo[i][0]);
            memo[i][1] = max(memo[i-1][0]+memo[i][1], max_value+memo[i][1]);

            ++idx;
            max_value = max(max_value, max(memo[idx][0], memo[idx][1]));
        }

        printf("%d\n", max(memo[n-1][0], memo[n-1][1]));

    }

    return 0;
}