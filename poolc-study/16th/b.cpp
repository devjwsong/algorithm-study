#include <iostream>
#include <vector>

using namespace std;

long long N;
long long k;

long long getSmallerNum(long long p) {
    long long res = 0;

    for (int i=1; i<=N; ++i) {
        long long num = p / i;
        num = min(num, N);

        res += num;
    }

    return res;
}

long long search(long long left, long long right) {
    if (left+1 == right) {
        return right;
    }
    
    long long cur = (left + right) / 2;

    long long num = getSmallerNum(cur);

    if (num >= k) {
        return search(left, cur);
    } else if (num < k) {
        return search(cur, right);
    }
}

int main() {

    scanf("%lld", &N);
    scanf("%lld", &k);

    printf("%lld\n", search(0, N*N));

    return 0;
}