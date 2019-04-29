#include <iostream>

using namespace std;

int T;

int getRoom(int H, int W, int N) {
    int result = 0;

    int col = (N-1) / H;
    int row = (N-1) % H;

    result = (row+1) * 100 + (col + 1);

    return result;
}

int main() {
    scanf("%d", &T);

    for (int test=0; test<T; ++test) {
        int H, W, N;

        scanf("%d %d %d", &H, &W, &N);

        int result = getRoom(H, W, N);
        printf("%d\n", result);
    }

    return 0;
}