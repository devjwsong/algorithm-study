#include <iostream>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    double scores[n];

    double max_value = 0.0;
    for (int i=0; i<n; ++i) {
        double input;
        scanf("%lf", &input);
        scores[i] = input;
        if (max_value < input) {
            max_value = input;
        }
    }

    double sum = 0.0;
    for (int i=0; i<n; ++i) {
        sum += scores[i]/max_value * 100.0;
    }

    printf("%.2lf\n", sum /n);

    return 0;
}