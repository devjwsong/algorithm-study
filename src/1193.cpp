#include <iostream>

using namespace std;

int main() {

    int X;
    scanf("%d", &X);

    int group = 1;
    while(1) {
        if (X <= (group*(group+1)/2) && X >= (group*(group+1)/2 - (group-1))) {
            break;
        }

        ++group;
    }

    int current = group*(group+1)/2 - (group-1);

    int divisor, divided;

    if (group % 2 == 1) {
        divisor = 1;
        divided = (group+1) - divisor;

        for (int i=0; i<group; ++i) {
            if (X == current) {
                break;
            }

            ++current;
            ++divisor;
            --divided;
        }
    } else {
        divided = 1;
        divisor = (group+1) - divided;

        for (int i=0; i<group; ++i) {
            if (X == current) {
                break;
            }

            ++current;
            ++divided;
            --divisor;
        }
    }

    printf("%d/%d\n", divided, divisor);

    return 0;
}