#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> seq;
int memo[201];

int main() {

    scanf("%d", &N);
    seq.assign(N+1, 0);

    for (int i=1; i<=N; ++i) {
        scanf("%d", &seq[i]);
        memo[i] = 1;
    }

    for (int i=1; i<=N; ++i) {
        for (int j=1; j<i; ++j) {
            if (seq[j] < seq[i]) {
                memo[i] = max(memo[i], memo[j]+1);
            }
        }
    }

    int len = 0;
    for (int i=1; i<=N; ++i) {
        len = max(len, memo[i]);
    }

    printf("%d\n", N-len);

    return 0;
}