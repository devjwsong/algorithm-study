#include <iostream>

using namespace std;

int T;

int getGCD(int a, int b) {

    while(1) {

        if (a > b) {
            a %= b;
        } else if (a < b) {
            b %= a;
        } else {
            return a;
        }

        if (a == 0) {
            return b;
        } else if (b == 0) {
            return a;
        }

    }

}

int getLCM(int a, int b) {

    int GCD = getGCD(a , b);

    return GCD * (a / GCD) * (b / GCD);

}

int main() {

    scanf("%d", &T);

    for (int test=0; test<T; ++test) {
        int M, N, x, y;
        scanf("%d %d %d %d", &M, &N, &x, &y);

        int count_year = 1;
        int current_x = 1;
        int current_y = 1;

        int diff_x = x - current_x;
        count_year += diff_x;
        current_x += diff_x;
        current_y += diff_x;

        if ((current_y-1) / N > 0) {
            current_y = (current_y-1) % N + 1;
        }

        int LCM = getLCM(M, N);

        while(1) {

            if (count_year > LCM) {
                count_year = -1;
                break;
            }

            if (y == current_y) {
                break;
            }

            current_y += M;
            if ((current_y-1) / 12 > 0) {
                current_y = (current_y-1) % N + 1;
            }
            
            count_year += M;
        }

        printf("%d\n", count_year);
    }

    return 0;
}