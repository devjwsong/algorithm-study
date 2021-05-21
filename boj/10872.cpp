#include <iostream>

using namespace std;

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    return factorial(n-1) * n;
}

int main() {

    int n;
    scanf("%d", &n);

    printf("%d\n", factorial(n));

    return 0;
}