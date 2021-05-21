#include <iostream>

using namespace std;

int T;
int A, B;

int get_gcd(int a, int b) {
    if (a == b) {
        return a;
    } else {
        if (a > b) {
            return get_gcd(a-b, b);
        } else {
            return get_gcd(a, b-a);
        }
    }
}

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        scanf("%d %d", &A, &B);

        int gcd = get_gcd(A, B);
        int a = A / gcd;
        int b = B / gcd;

        printf("%d\n", gcd * a * b);
    }

    return 0;
}