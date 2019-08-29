#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long memo[101];

int main() {

    scanf("%d", &N);

    for (int i=1; i<=N; ++i) {
        for (int j=i-1; j>=0; --j)  {
            if (j >= i-2) {
                memo[i] = max(memo[i], memo[j]+(i-j));
            } else {
                memo[i] = max(memo[i], memo[j]+memo[j]*(i-j-2));
            }
        }
    }

    printf("%lld\n", memo[N]);

    return 0;
}