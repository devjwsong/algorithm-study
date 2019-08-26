#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int m;
int dists[101][101];

const int INF = 100001;

void search() {
    for (int k=1; k<=n; ++k) {
        for (int i=1; i<=n; ++i) {
            for (int j=1; j<=n; ++j) {
                if (dists[i][j] > dists[i][k] + dists[k][j]) {
                    dists[i][j] = dists[i][k] + dists[k][j];
                }
            }
        }
    }
}

int main() {

    scanf("%d", &n);
    scanf("%d", &m);

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (i == j) {
                dists[i][j] = 0;
            } else {
                dists[i][j] = INF;
            }
        }
    }

    for (int i=0; i<m; ++i) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        dists[a][b] = min(dists[a][b], w);
    }

    search();

    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (i == j || dists[i][j] == INF) {
                printf("%d ", 0);
            } else {
                printf("%d ", dists[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}