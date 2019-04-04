#include <iostream>
#include <utility>
#include <stack>

using namespace std;

int memo[1000001];

int solve(int n) {

    for(int i=n; i>=1; --i) {

        if (i == 1) {
            return memo[1];
        }

        if (i % 3 == 0) {
            if (!memo[i/3]) {
                memo[i/3] = memo[i] + 1;
            } else {
                memo[i/3] = min(memo[i]+1, memo[i/3]);
            }
        }

        if (i % 2 == 0) {
            if (!memo[i/2]) {
                memo[i/2] = memo[i] + 1;
            } else {
                memo[i/2] = min(memo[i]+1, memo[i/2]);
            }
        }

        if (!memo[i-1]) {
            memo[i-1] = memo[i] + 1;
        } else {
            memo[i-1] = min(memo[i]+1, memo[i-1]);
        }
    }

}

int main() {

    int n = 0;
    scanf("%d", &n);

    int result = solve(n);
    printf("%d\n", result);

}