#include <iostream>
#include <cmath>

using namespace std;

int findGroup(int n) {
    --n;
    float group = (sqrt(8.0*(float)n + 1.0)-1.0) / 2.0;

    return (int) group + 1;
}

int main() {

    int T;
    scanf("%d", &T);

    for (int test=0; test<T; ++test) {
        int x, y;
        scanf("%d %d", &x, &y);

        int dist = y - x;
        int result = 0;

        int k = (int) ceil(sqrt((float) dist)); 
        int max_dist_odd = k * k;

        int max_dist_even = k * k - k;

        if (dist == 1) {
            result = 1;
        } else if (dist <= max_dist_even) {
            result = (k-1) * 2;
        } else {
            result = (k-1) * 2 + 1;
        }

        printf("%d\n", result);

    }

    return 0;
}