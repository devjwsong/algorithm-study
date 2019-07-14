#include <iostream>

using namespace std;

int main() {

    int a,b;
    scanf("%d %d", &a, &b);

    long long answer = 1;
    for (long long i=a; i<=b; ++i) {
        answer *= (i * (i+1) / 2);
        answer %= 14579;
    }

    printf("%lld\n", answer);

    return 0;
}