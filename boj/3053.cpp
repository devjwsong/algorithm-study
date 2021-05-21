#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int r;
    scanf("%d", &r);

    double ans1 = (double) r * (double) r * M_PI;
    double ans2 = 2.0 * (double) r * (double) r;

    printf("%.6lf\n", ans1);
    printf("%.6lf\n", ans2);

    return 0;
}