#include <iostream>

using namespace std;

int N, E;
int dists[801][801];

int x, y;

const int INF = 100000000;

#define x1 (dists[1][x] == INF || dists[x][y] == INF || dists[y][N] == INF)
#define x2 (dists[1][y] == INF || dists[y][x] == INF || dists[x][N] == INF)

void floyd() {
    for (int k=1; k<=N; ++k) {
        for (int i=1; i<=N; ++i) {
            for (int j=1; j<=N; ++j) {
                if (dists[i][j] > dists[i][k] + dists[k][j]) {
                    dists[i][j] = dists[i][k] + dists[k][j];
                }
            }
        }
    }
}

int main() {

    scanf("%d %d", &N, &E);

    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=N; ++c) {
            if (r == c) {
                dists[r][c] = 0;
            } else {
                dists[r][c] = INF;
            }
        }
    }

    for (int i=0; i<E; ++i) {
        int a, b, p;
        scanf("%d %d %d", &a, &b, &p);

        dists[a][b] = min(dists[a][b], p);
        dists[b][a] = min(dists[b][a], p);
    }

    scanf("%d %d", &x, &y);

    floyd();

    if (x1 && x2) {
        printf("%d\n", -1);
    } else if (!x1 && x2) {
        printf("%d\n", dists[1][x] + dists[x][y] + dists[y][N]);
    } else if (x1 && !x2) {
        printf("%d\n", dists[1][y] + dists[y][x] + dists[x][N]);
    } else {
        printf("%d\n", min(dists[1][x] + dists[x][y] + dists[y][N], dists[1][y] + dists[y][x] + dists[x][N]));
    }

    return 0;
}