#include <iostream>

using namespace std;

int main() {

    int inputs[3];
    int digits[10] = {0, };

    for (int i=0; i<3; ++i) {
        scanf("%d", &inputs[i]);
    }

    int value = inputs[0] * inputs[1] * inputs[2];

    string str = to_string(value);

    for (int i=0; i<str.size(); ++i) {
        digits[str[i] - '0'] += 1;
    }

    for (int i=0; i<10; ++i) {
        printf("%d\n", digits[i]);
    }

    return 0;
}