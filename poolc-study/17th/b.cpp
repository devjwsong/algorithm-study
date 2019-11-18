#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> mat;
vector<vector<int>> pSum;
int K;

int main() {

    scanf("%d %d", &N, &M);
    mat.assign(N+1, vector<int> (M+1, 0));
    pSum.assign(N+1, vector<int> (M+1, 0));

    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=M; ++c) {
            scanf("%d", &mat[r][c]);
            pSum[r][c] = mat[r][c];
        }
    }

    scanf("%d", &K);

    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=M; ++c) {
            pSum[r][c] += pSum[r][c-1];
            pSum[r][c] += pSum[r-1][c];
            pSum[r][c] -= pSum[r-1][c-1];
        }
    }

    for (int t=1; t<=K; ++t) {
        int i, j, x, y;
        scanf("%d %d %d %d", &i, &j, &x, &y);

        printf("%d\n", pSum[x][y]-pSum[x][j-1]-pSum[i-1][y]+pSum[i-1][j-1]);
    }

    return 0;
}