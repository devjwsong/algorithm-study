#include <iostream>

using namespace std;

int N, M, K;

int main() {

    scanf("%d %d %d", &N, &M, &K);

    int answer = 0;

    while(1) {
        if (N-2>=0 && M-1>=0 && (N+M-3) >= K) {
            N -= 2;
            M -= 1;
            ++answer;
        } else {
            break;
        }
    }

    printf("%d\n", answer);

    return 0;
}