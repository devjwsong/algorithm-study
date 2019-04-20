#include <iostream>
#include <vector>

using namespace std;

int main() {

    int C;
    scanf("%d", &C);

    for (int test=0; test<C; ++test) {
        double n;
        scanf("%lf", &n);

        double sum = 0.0;
        vector<double> scores;

        for (int i=0; i<n; ++i) {
            double input;
            scanf("%lf", &input);
            sum += input;
            scores.push_back(input);
        }

        double average = sum / n;
        double well = 0.0;

        for (int i=0; i<scores.size(); ++i) {
            if (scores[i] > average) {
                well += 1.0;
            }
        }

        printf("%.3lf%%\n", well / n * 100.0);
    }

    return 0;
}