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

    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);

    int sum = 0;
    int min = M + 1;

    for (int i=N; i<=M; ++i) {
        if (isPrime(i)) {
            sum += i;
            if (min >= i) {
                min = i;
            }
        }
    }
    
    if (sum == 0) {
        printf("%d\n", -1);
    } else {
        printf("%d\n", sum);
        printf("%d\n", min);
    }

    return 0;
}