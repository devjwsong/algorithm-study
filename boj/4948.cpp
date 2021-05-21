#include <iostream>
#include <cmath>

using namespace std;

int filter(int start, int end) {
    bool nums[123456 * 2 + 1] = {false, };

    int count = 0;
    int divisor = 2;
    int limit = (int) sqrt(end);

    while(1) {
        if (divisor > limit) {
            break;
        }

        int smallest = (int) ceil(start / divisor);
        int largest = (int) floor(end / divisor);

        for (int i=smallest; i<=largest; ++i) {
            if (i != 1) {
                nums[divisor * i] = true;
            }
        }

        ++divisor;
    }

    for (int i=start; i<=end; ++i) {
        if (i != 1) {
            if (nums[i] == 0) {
                ++count;
            }
        }
    }

    return count;
}

int main() {

    while(1) {
        int input;
        scanf("%d", &input);

        if (input == 0) {
            break;
        } else {
            printf("%d\n", filter(input+1, input*2));
        }
    }

    return 0;
}