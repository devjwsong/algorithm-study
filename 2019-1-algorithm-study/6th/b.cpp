#include <iostream>

using namespace std;

int T;

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        int input;
        scanf("%d", &input);

        if (input == 4) {
            printf("2\n");
        } else if (input < 4 || input == 6) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    }

    return 0;
}