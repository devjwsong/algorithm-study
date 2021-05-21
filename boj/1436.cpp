#include <iostream>

using namespace std;

int N;

bool isRight(int n) {
    int count = 0;

    while(n != 0) {
        if (n % 10 == 6) {
            ++count;

            if (count == 3) {
                break;
            }
        } else {
            count = 0;
        }

        n /= 10;
    }

    if (count == 3) {
        return true;
    } else {
        return false;
    }
}

int main() {

    scanf("%d", &N);

    int count = 0;
    int cur = 0;

    while(1) {
        ++cur;

        if (isRight(cur)) {
            ++count;
        }

        if (count == N) {
            break;
        }
    }

    printf("%d\n", cur);

    return 0;
}