#include <iostream>

using namespace std;

int nums[10001];

void d(int n) {

    if (n > 10000) {
        return;
    }

    int cpy = n;
    int sum = 0;
    while(1) {
        sum += (cpy % 10);
        cpy -= (cpy % 10);

        if (cpy == 0) {
            break;
        }

        cpy /= 10;
    }

    if (n + sum <= 10000) {
        nums[n+sum] = n;
    }

    d(n+1);

}

int main() {

    d(1);

    for (int i=1; i<10001; ++i) {
        if (nums[i] == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}