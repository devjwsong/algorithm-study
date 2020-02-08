#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
int memo[101][51];

vector<int> seq;
int pSum[101];

const int INF = 1000000000;

int main() {

    scanf("%d %d", &N, &M);

    seq.assign(N+1, 0);
    for (int i=1; i<=N; ++i) {
        scanf("%d", &seq[i]);
        pSum[i] = seq[i];
    }

    for (int i=1; i<=N; ++i) {
        pSum[i] += pSum[i-1];
    }

    for (int i=0; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            memo[i][j] = -INF;
        };
    }

    for (int i=1; i<=N; ++i) {
        int max_group = (i+1)/2;
        max_group = min(max_group, M);
        for (int j=1; j<=max_group; ++j) {
            memo[i][j] = memo[i-1][j];
            for (int k=i; k>=1; --k) {
                if (k-2 < 0) {
                    if (j < 2) {
                        memo[i][j] = max(memo[i][j], pSum[i] - pSum[k-1]);
                    }
                } else {
                    memo[i][j] = max(memo[i][j], memo[k-2][j-1] + pSum[i] - pSum[k-1]);
                }
            }   
        }
    }

    // cout<<"----------------"<<endl;
    // for (int i=1; i<=N; ++i) {
    //     for (int j=0; j<=M; ++j) {
    //         cout<<i<<" "<<j<<" "<<memo[i][j]<<endl;
    //     }
    // }

    printf("%d\n", memo[N][M]);

    return 0;
}