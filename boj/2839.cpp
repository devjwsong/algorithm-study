#include <iostream>

using namespace std;

int main() {
    int num3, num5 = 0;
    int load = 0;
    scanf("%d", &load);

    num5 = load / 5;

    int result = -1;

    while(1) {
        if (num5 == -1) {
            break;
        }

        if ((load-(num5*5)) % 3 == 0) {
            num3 = (load-(num5*5)) / 3;
            result = num3 + num5;
            break;
        }

        --num5;
    }

    printf("%d\n", result);

    return 0;
}