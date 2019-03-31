#include <iostream>

using namespace std;

int num;
int stairs[300];
int memo[300][2];

int solve() {

    int index = 0;

    memo[0][0] = stairs[0];
    memo[1][0] = stairs[1];

    while(1) {

        if (index >= 1) {
            int max_value = 0;
            for (int k=0; k<1; ++k) {
                if (max_value <= memo[index-1][k]) {
                    max_value = memo[index-1][k];
                }
            }
            memo[index][1] = max_value + stairs[index];
        }

        if (index >= 2) {
            int max_value = 0;
            for (int k=0; k<2; ++k) {
                if (max_value <= memo[index-2][k]) {
                    max_value = memo[index-2][k];
                }
            }
            memo[index][0] = max_value + stairs[index];
        }

        if (index == num-1) {
            break;
        }

        ++index;

    }

    return max(memo[num-1][0], memo[num-1][1]);
}

int main() {

    scanf("%d", &num);

    for (int i=0; i<num; ++i) {
        int input = 0;
        scanf("%d", &input);
        stairs[i] = input;
    }

    int result = solve();
    printf("%d\n", result);

    return 0;
}