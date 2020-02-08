#include <iostream>

using namespace std;

int N;
int dists[100][100];

const int INF = 100000;

void search() {
    for (int k=0; k<N; ++k) {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                if (dists[i][j] > dists[i][k] + dists[k][j]) {
                    dists[i][j] = dists[i][k] + dists[k][j];
                }
            }
        }
    }
}

int main() {

    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            int p;
            scanf("%d", &p);

            if (p == 0) {
                dists[i][j] = INF;
            } else {
                dists[i][j] = 1;
            }
        }
    }

    search();

    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (dists[i][j] == INF) {
                printf("%d ", 0);
            } else {
                printf("%d ", 1);
            }
        }
        printf("\n");
    }

    return 0;
}