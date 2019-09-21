#include <iostream>

using namespace std;

int N;

int main() {

    scanf("%d", &N);

    int answer = 0;

    for (int i=1; i<=N; ++i) {
        int value = i;
        int cur = i;

        while(cur != 0) {
            value += cur % 10;
            cur /= 10;
        }

        if (value == N) {
            answer = i;
            break;
        }
    }

    printf("%d\n", answer);

    return 0;
}