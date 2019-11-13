#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> cows;
int memo[10001];
int pSum[10001];

int main() {

    scanf("%d %d", &N, &K);

    for (int i=0; i<N; ++i) {
        int p;
        scanf("%d", &p);
        cows.push_back(p);
    }

    memo[0] = cows[0];

    for (int i=1; i<N; ++i) {
        int largest = cows[i];
        for (int j=1; j<=K; ++j) {
            largest = max(largest, cows[i-j+1]);
            if (i>=j) {
                memo[i] = max(memo[i], memo[i-j] + j*largest);
            } else if (j==i+1) {
                memo[i] = max(memo[i], j*largest);
            }
        }
    }
    printf("%d\n", memo[N-1]);

    return 0;
}