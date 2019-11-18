#include <iostream>

using namespace std;

long long N, M, K;
long long tree[4194305];

void update(long long leaf) {
    long long cur = leaf/2;
    while(1) {
        tree[cur] = tree[cur*2] + tree[cur*2+1];

        if (cur <= 1) {
            break;
        }

        cur /= 2;
    }
}

long long query(long long left, long long right) {
    long long sum = 0;

    while(1) {
        if (left >= right) {
            break;
        }

        if (left % 2 == 1) {
            sum += tree[left];
            ++left;
        }

        if (right % 2 == 0) {
            sum += tree[right];
            --right;
        }

        left /= 2;
        right /= 2;
    }

    if (left == right) {
        sum += tree[left];
    }

    return sum;
}

int main() {

    scanf("%lld %lld %lld", &N, &M, &K);

    long long base = 1;
    while(1) {
        if (base >= N) {
            break;
        }
        base *= 2;
    }
    --base;

    for (long long i=1; i<=N; ++i) {
        long long p;
        scanf("%lld", &p);
        tree[base+i] = p;
        update(base+i);
    }

    // for (long long i=1; i<(base+1)*2; ++i) {
    //     cout<<tree[i]<<" ";
    // }
    // cout<<endl;

    for (long long t=1; t<=(M+K); ++t) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);

        if (a == 1) {
            tree[base+b] = c;
            update(base+b);
        } else if (a == 2) {
            printf("%lld\n", query(base+b, base+c));
        }

        // for (long long i=1; i<(base+1)*2; ++i) {
        //     cout<<tree[i]<<" ";
        // }
        // cout<<endl;
        // }
    }

    return 0;
}