#include <iostream>
#include <vector>

using namespace std;

int N; 
long long S;
vector<long long> seq;
vector<long long> pSum;

int main() {

    scanf("%d %lld", &N, &S);
    seq.assign(N+1, 0);
    pSum.assign(N+1, 0);

    for (int i=1; i<=N; ++i) {
        scanf("%lld", &seq[i]);
        pSum[i] = seq[i];
    }

    for (int i=1; i<=N; ++i) {
        pSum[i] += pSum[i-1];
    }

    int low = 0;
    int high = 0;
    int len = N;

    while(high <= N && low <= high) {
        int p = pSum[high] - pSum[low];
        if (p < S) {
            ++high;
        } else if (p == S) {
            len = min(len, high-low);
            ++high;
        } else if (p > S) {
            len = min(len, high-low);
            ++low;
        }
    }

    if (pSum[N] - pSum[0] < S) {
        printf("0\n");
    } else {
        printf("%d\n", len);
    }

    return 0;
}