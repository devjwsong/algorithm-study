#include <iostream>
#include <vector>

using namespace std;

int N, M;
int x, y;
int K;

vector<vector<int>> map;

int dirR[] = {0, 0, 0, -1, 1};
int dirC[] = {0, 1, -1, 0, 0};

int dice[6];

int roll(int ord) {
    int nextX = x + dirR[ord];
    int nextY = y + dirC[ord];

    if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) {
        return -1;
    }

    x = nextX;
    y = nextY;

    int temp = -1;
    if (ord == 1) {
        temp = dice[5];
        dice[5] = dice[3];
        dice[3] = dice[2];
        dice[2] = dice[0];
        dice[0] = temp;
    } else if (ord == 2) {
        temp = dice[2];
        dice[2] = dice[3];
        dice[3] = dice[5];
        dice[5] = dice[0];
        dice[0] = temp;
    } else if (ord == 3) {
        temp = dice[4];
        dice[4] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[0];
        dice[0] = temp;
    } else if (ord == 4) {
        temp = dice[1];
        dice[1] = dice[3];
        dice[3] = dice[4];
        dice[4] = dice[0];
        dice[0] = temp;
    }

    if (map[x][y] == 0) {
        map[x][y] = dice[3];
    } else {
        dice[3] = map[x][y];
        map[x][y] = 0;
    }

    return dice[0];
}

int main() {

    scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);

    map.assign(N, vector<int> (M, 0));
    for (int r=0; r<N; ++r) {
        for (int c=0; c<M; ++c) {
            scanf("%d", &map[r][c]);
        }
    }

    for (int i=0; i<K; ++i) {
        int ord;
        scanf("%d", &ord);

        int result = roll(ord);
        if (result != -1) {
            printf("%d\n", result);
        }
    }

    return 0;
}