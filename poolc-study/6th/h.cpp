#include <iostream>

using namespace std;

int T;

int main() {
    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        int A, B;
        scanf("%d %d", &A, &B);

        int check[1024] = {0, };

        while(1) {
            if (A == 1) {
                ++check[A];
                break;
            } else {
                ++check[A];
                A /= 2;
            }
        }

        int ans = 0;
        while(1) {
            if (check[B] > 0) {
                ans = B;
                break;
            } else {
                B /= 2;
            }
        }

        printf("%d\n", ans * 10);
    }

    return 0;
}