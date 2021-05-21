#include <iostream>

using namespace std;

int X[1001];
int Y[1001];

int main() {

    int ans_x, ans_y;

    for (int i=0; i<3; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);

        ++X[x];
        ++Y[y];
    }

    for (int i=1; i<=1000; ++i) {
        if (X[i] == 1) {
            ans_x = i;
        }

        if (Y[i] == 1) {
            ans_y = i;
        }
    }

    printf("%d %d\n", ans_x, ans_y);

    return 0;
}