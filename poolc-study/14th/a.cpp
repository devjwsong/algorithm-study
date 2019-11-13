#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> coins;

int main() {

    scanf("%d %d", &N, &K);
    coins.assign(N, 0);

    for (int i=0; i<N; ++i) {
        scanf("%d", &coins[i]);
    }

    int answer = 0;

    for (int i=N-1; i>=0; --i) {
        if (K == 0) break;

        if (coins[i] <= K) {
            int num = K / coins[i];
            answer += num;
            K -= (num * coins[i]);
        }
    }

    printf("%d\n", answer);

    return 0;
}