#include <iostream>

using namespace std;

int A, B, C;

int main() {

    scanf("%d %d %d", &A, &B, &C);

    if (B >= C) {
        printf("%d\n", -1);
    } else {
        int n = A / (C-B) + 1;

        printf("%d\n", n);
    }
    
    return 0;
}