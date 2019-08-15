#include <iostream>
#include <vector>
#include <set>

using namespace std;

int N;
int degree[100001];

int main() {

    scanf("%d", &N);

    for (int i=0; i<N-1; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        ++degree[a];
        ++degree[b];
    }

    int result = 0;

    for (int i=1; i<=N; ++i) {
        int colors = degree[i] + 1;

        result = max(result, colors);
    }

    printf("%d\n", result);

    return 0;
}