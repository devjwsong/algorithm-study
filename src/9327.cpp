#include <iostream>
#include <vector>

using namespace std;

int T;
int N, M;

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        scanf("%d %d", &N, &M);

        for (int i=1; i<=M; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);
        }

        printf("%d\n", N-1);
    }

    return 0;
}