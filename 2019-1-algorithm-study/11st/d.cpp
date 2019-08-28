#include <iostream>

using namespace std;

int T;
int n;

int memo[10];

int main() {

    scanf("%d", &T);
    

    for (int t=1; t<=T; ++t) {
        scanf("%d", &n);

        for (int i=0; i<=n; ++i) {
            memo[i] = 0;
        }

        memo[1] = 1;
        memo[2] = 1;
        memo[3] = 1;

        for (int i=2; i<=n; ++i) {
            if (i-1 >= 1) {
                memo[i] += memo[i-1];
            }

            if (i-2 >= 1) {
                memo[i] += memo[i-2];
            }

            if (i-3 >= 1) {
                memo[i] += memo[i-3];
            }
        }

        printf("%d\n", memo[n]);
    }

    return 0;
}