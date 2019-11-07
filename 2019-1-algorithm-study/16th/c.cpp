#include <iostream>
#include <vector>

using namespace std;

long long N, M;
vector<long long> times;

long long getNum(long long p) {
    long long res = 0;

    for (int i=0; i<N; ++i) {
        res += (p / times[i]);
    }

    return res;
}

long long search(long long left, long long right) {
    if (left + 1 == right) {
        return right;
    }

    long long cur = (left + right) / 2;

    long long num = getNum(cur);

    if (num >= M) {
        return search(left, cur);
    } else {
        return search(cur, right);
    }
}

int main() {

    scanf("%lld %lld", &N, &M);
    times.assign(N, 0);

    long long max_val = 0;

    for (int i=0; i<N; ++i) {
        scanf("%lld", &times[i]);

        max_val = max(max_val, times[i]);
    }

    printf("%lld\n", search(0, max_val*M+1));

    return 0;
}