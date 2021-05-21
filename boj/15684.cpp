#include <iostream>
#include <algorithm>

using namespace std;

int N, M, H;
bool leds[31][11];

const int INF = 10000000;

int answer = INF;

bool test() {

    for (int i=1; i<=N; ++i) {
        int cur = i;

        for (int r=1; r<=H; ++r) {
            if (leds[r][cur]) {
                cur += 1;
            } else if (leds[r][cur-1]) {
                cur -= 1;
            }
        }

        if (cur != i) {
            return false;
        }
    }

    return true;
}

void dfs(int row, int count) {
    if (count > 3) {
        return;
    }

    if (test()) {
        answer = min(answer, count);
        return;
    }

    for (int r=row; r<=H; ++r) {
        for (int c=1; c<=N-1; ++c){
            if (leds[r][c] || (c-1 >= 1 && leds[r][c-1]) || (c+1 <= N-1 && leds[r][c+1])) {
                continue;
            } else {
                leds[r][c] = true;
                dfs(r, count + 1);
                leds[r][c] = false;
            }
        } 
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &H);

    for (int i=1; i<=M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        leds[a][b] = true;
    }

    dfs(1, 0);
    
    if (answer == INF) {
        answer = -1;
    }

    printf("%d\n", answer);

    return 0;
}