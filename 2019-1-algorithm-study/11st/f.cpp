#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> W;
vector<vector<int>> memo;

const int INF = 20000000;

int TSP(int cur, int state) {
    int ret = INF;

    if (memo[cur][state] != 0) {
        return memo[cur][state];
    } else {
        if (state == (1<<N)-1) {
            if (W[cur][0] != 0) {
                return W[cur][0];
            } else {
                return INF;
            }
        }

        for (int i=0; i<N; ++i) {
            if ((state & (1<<i)) || (W[cur][i] == 0)) {
                continue;
            }
            ret = min(ret, TSP(i, state | (1<<i)) + W[cur][i]);
        }
        
        memo[cur][state] = ret;
    }

    return ret;
}

int main() {

    scanf("%d", &N);

    W.assign(N, vector<int> (N, 0));
    memo.assign(N, vector<int> (1 << N, 0));

    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            scanf("%d", &W[i][j]);
        }
    }

    printf("%d\n", TSP(0, 1));

    return 0;
}