#include <iostream>

using namespace std;

int T;

int getDistSquare(int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        int answer = -1;
        int x1, y1, r1, x2, y2, r2;
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

        int d = getDistSquare(x1, y1, x2, y2);

        if (d == (r1+r2)*(r1+r2)) {
            answer = 1;
        } else if (d > (r1+r2)*(r1+r2)) {
            answer = 0;
        } else {
            if (d == (r1-r2)*(r1-r2)) {
                if (d == 0 && (r1-r2 == 0)) {
                    answer = -1;
                } else {
                    answer = 1;
                }
            } else if (d < (r1-r2)*(r1-r2)) {
                answer = 0;
            } else {
                answer = 2;
            }
        }

        printf("%d\n", answer);
    }

    return 0;
}