#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> seq;

int memo[1001];

int main() {

    scanf("%d", &N);

    seq.assign(N+1, 0);

    for (int i=1; i<=N; ++i) {
        int p;
        scanf("%d", &p);
        seq[i] = p;
    }

    memo[0] = 0;
    
    for (int i=1; i<=N; ++i) {
        for (int j=0; j<i; ++j) {
            if (seq[j] < seq[i]) {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
    }

    int answer = 0;
    for (int i=1; i<=N; ++i) {
        answer = max(answer, memo[i]);
    }
    printf("%d\n", answer);


    return 0;
}