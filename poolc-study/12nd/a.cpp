#include <iostream>
#include <algorithm>

using namespace std;

int N;

int max_memo[2][3];
int min_memo[2][3];

void updateMax(int i, int a, int b, int c) {
    if (i % 2 == 1) {
        max_memo[1][0] = max(max_memo[1][0], max(max_memo[0][0]+a, max_memo[0][1]+a));
        max_memo[1][1] = max(max_memo[1][1], max(max(max_memo[0][0]+b, max_memo[0][1]+b), max_memo[0][2]+b));
        max_memo[1][2] = max(max_memo[1][2], max(max_memo[0][1]+c, max_memo[0][2]+c));
    } else {
        max_memo[0][0] = max(max_memo[0][0], max(max_memo[1][0]+a, max_memo[1][1]+a));
        max_memo[0][1] = max(max_memo[0][1], max(max(max_memo[1][0]+b, max_memo[1][1]+b), max_memo[1][2]+b));
        max_memo[0][2] = max(max_memo[0][2], max(max_memo[1][1]+c, max_memo[1][2]+c));
    }
}

void updateMin(int i, int a, int b, int c) {
    if (i % 2 == 1) {
        min_memo[1][0] = min(min_memo[0][0]+a, min_memo[0][1]+a);
        min_memo[1][1] = min(min(min_memo[0][0]+b, min_memo[0][1]+b), min_memo[0][2]+b);
        min_memo[1][2] = min(min_memo[0][1]+c, min_memo[0][2]+c);
    } else {
        min_memo[0][0] = min(min_memo[1][0]+a, min_memo[1][1]+a);
        min_memo[0][1] = min(min(min_memo[1][0]+b, min_memo[1][1]+b), min_memo[1][2]+b);
        min_memo[0][2] = min(min_memo[1][1]+c, min_memo[1][2]+c);
    }
}

int main() {

    scanf("%d", &N);

    for (int i=1; i<=N; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (i == 1) {
            max_memo[1][0] = a;
            max_memo[1][1] = b;
            max_memo[1][2] = c;
            min_memo[1][0] = a;
            min_memo[1][1] = b;
            min_memo[1][2] = c;
        } else {
            updateMax(i, a, b, c);
            updateMin(i, a, b, c);
        }
    }

    int max_answer = 0;
    int min_answer = 1000000;

    if (N % 2 == 1) {
        max_answer = max(max_answer, max(max(max_memo[1][0], max_memo[1][1]), max_memo[1][2]));
        min_answer = min(min_answer, min(min(min_memo[1][0], min_memo[1][1]), min_memo[1][2]));
    } else {
        max_answer = max(max_answer, max(max(max_memo[0][0], max_memo[0][1]), max_memo[0][2]));
        min_answer = min(min_answer, min(min(min_memo[0][0], min_memo[0][1]), min_memo[0][2]));
    }

    printf("%d %d\n", max_answer, min_answer);

    return 0;
}