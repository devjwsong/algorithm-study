#include <iostream>

using namespace std;

int T;

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        int L, U, X;
        scanf("%d %d %d", &L, &U, &X);

        int answer = 0;

        if (X > U) {
            answer = -1;
        } else if (X >= L) {
            answer = 0;
        } else if (X < L) {
            answer = (L-X);
        }

        printf("#%d %d\n", t, answer);
    } 

    return 0;
}