#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int T;

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        int N;
        scanf("%d", &N);

        vector<int> arr (N, 0);
        for (int i=0; i<N; ++i) {
            scanf("%d", &arr[i]);
        }

        vector<int> pSum = arr;
        for (int i=1; i<N; ++i) {
            pSum[i] += pSum[i-1];
        }

        int minPSum = 0;
        int result = -INT_MAX;
        for (int i=0; i<N; ++i) {
            result = max(pSum[i]-minPSum, result);
            minPSum = min(pSum[i], minPSum);
        }

        printf("%d\n", result);
    }

    return 0;
}