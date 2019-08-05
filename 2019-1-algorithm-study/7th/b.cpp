#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> times;

int main() {

    scanf("%d", &N);

    times.assign(1001, 0);

    for (int i=0; i<N; ++i) {
        int s, t, b;
        scanf("%d %d %d", &s, &t, &b);

        for (int j=s; j<=t; ++j) {
            times[j] += b;
        }
    }

    int maxNum = 0;
    int use = 0;

    for (int i=1; i<=1000; ++i) {
        use = times[i];

        if (use >= maxNum) {
            maxNum = use;
        }
    }

    printf("%d\n", maxNum);

    return 0;
}