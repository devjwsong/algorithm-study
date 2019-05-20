#include <iostream>
#include <cmath>

using namespace std;

bool nums[1000001];

void filter(int start, int end) {
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
}

int main() {

    int M, N;
    scanf("%d %d", &M, &N);

    filter(M, N);

    for (int i=M; i<=N; ++i) {
        if (i != 1 && nums[i] == false) {
            printf("%d\n", i);
        }
    }

    return 0;
}