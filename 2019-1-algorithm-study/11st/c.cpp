#include <iostream>

using namespace std;

int N;
struct State memo[101][5];

struct State {
    State (int _num, bool _all, int _buffer) {
        num = _num;
        all = _all;
        buffer = _buffer;
    }

    int num;
    bool all;
    int buffer;
};

struct State findMax(int i, int start, int end) {
    struct State answer (0, false, 0);

    for (int j=start; j<=end; ++j) {
        if (answer.num <= memo[i][j].num) {
            answer = memo[i][j];
        }
    }

    return answer
}

int main() {

    scanf("%d", &N);

    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=4; ++j) {
            if (j == 1) {
                struct State maxState = findMax(i-1, 1, 4);
                maxState.num += 1;
                memo[i][j] = maxState;
            } else if (j == 2) {
                struct State maxState = findMax(i-1, 1, 4);
                maxState.all = true;
                memo[i][j] = maxState;
            } else if (j == 3) {
                struct State maxState = memo[i-1][2];
                maxState.buffer = maxState.num;
                memo[i][j] = maxState;
            } else if (j == 4) {
                struct State maxState = memo[i-1][3];
            }
        }
    }

    return 0;
}