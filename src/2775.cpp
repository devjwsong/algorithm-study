#include <iostream>

using namespace std;

int T;

int getSum(int k, int n) {

    if (k == 0) {
        return n;
    }

    int sum = 0;

    for (int i=1; i<=n; ++i) {
        sum += getSum(k-1, i);
    }

    return sum;

}

int main() {

    scanf("%d", &T);

    for (int test=0; test<T; ++test) {
        int k, n;
        scanf("%d", &k);
        scanf("%d", &n);

        printf("%d\n", getSum(k, n));
    }

    return 0;
}