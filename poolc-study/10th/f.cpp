#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
vector<pair<int, int>> graph[501];
int dists[501];

const int INF = 200000000;

bool search() {
    dists[1] = 0;
    bool result = true;

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

    scanf("%d %d", &N, &M);

    for (int i=1; i<=N; ++i) {
        dists[i] = INF;
    }

    for (int i=0; i<M; ++i) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        graph[a].push_back({b, w});
    }

    bool result = search();

    if (!result) {
        printf("%d\n", -1);
    } else {
        for (int i=2; i<=N; ++i) {
            if (dists[i] == INF) {
                printf("-1\n");
            } else {
                printf("%d\n", dists[i]);
            }
        }
    }

    return 0;
}