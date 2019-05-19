#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n == 1) {
        return false;
    }

    bool answer = true;

    int divisor = 2;

    while(1) {
        if (divisor >= n) {
            break;
        }

        if (n % divisor == 0) {
            answer = false;
            break;
        } else {
            ++divisor;
        }
    }

    return answer;
}

int main() {

    int N;
    scanf("%d", &N);

    int count = 0;

    for (int i=0; i<N; ++i) {
        int n;
        scanf("%d", &n);
        if (isPrime(n)) {
            ++count;
        }
    }

    printf("%d\n", count);

    return 0;
}