#include <iostream>
#include <vector>

using namespace std;

int T;
int N, M, W;

vector<pair<int, int>> graph[501];
int dists[501];

const int INF = 100000000;

bool bellman() {
    bool result = true;
    dists[1] = 0;

    for (int k=1; k<=N; ++k) {
        for (int i=1; i<=N; ++i) {
            for (int j=0; j<graph[i].size(); ++j) {
                int new_v = graph[i][j].first;
                int new_w = graph[i][j].second;

                if (dists[i] != INF && dists[new_v] > dists[i] + new_w) {
                    dists[new_v] = dists[i] + new_w;


                    if (k == N) {
                        result = false;
                    }
                }
            }
        }
    }

    return result;
}

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        scanf("%d %d %d", &N, &M, &W);

        for (int i=0; i<M; ++i) {
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);

            graph[S].push_back({E, T});
            graph[E].push_back({S, T});
        }

        for (int i=0; i<W; ++i) {
            int S, E, T;
            scanf("%d %d %d", &S, &E, &T);

            graph[S].push_back({E, -T});
        }

        for (int i=1; i<=N; ++i) {
            dists[i] = INF;
        }

        if (!bellman()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }

        for (int i=1; i<=N; ++i) {
            dists[i] = 0;
            graph[i].clear();
        }
    }

    return 0;
}