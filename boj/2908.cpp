#include <iostream>

using namespace std;

int reverse(int n) {
    int first = n / 100;
    int second = n / 10 - first * 10;
    int third = n % 10;

    return third * 100 + second * 10 + first;
}

int main() {

    int a, b;
    scanf("%d %d", &a, &b);

    int a_reversed = reverse(a);
    int b_reversed = reverse(b);

    if (a_reversed > b_reversed) {
        printf("%d\n", a_reversed);
    } else {
        printf("%d\n", b_reversed);
    }

    return 0;
}