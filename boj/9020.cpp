#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }

    int limit = (int) sqrt(n);
    int divisor = 2;

    while(1) {
        if (divisor >= n) {
            break;
        }

        if (n % divisor == 0) {
            return false;
        } else {
            ++divisor;
        }
    }

    return true;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int test=0; test<T; ++test) {
        int n;
        scanf("%d", &n);

        int small = n/2;
        int large = n/2;

        while(1) {

            if (isPrime(small) && isPrime(large)) {
                break;
            } else {
                ++large;
                --small;
            }
        }

        printf("%d %d\n", small, large);
    }

    return 0;
}