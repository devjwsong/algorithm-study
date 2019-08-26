#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
vector<pair<int, int>> graph[501];
int dists[501];

bool search() {
    dists[1] = 0;
    bool result = true;

    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            for (int k=0; k<graph[j].size(); ++k) {
                int next_v = graph[j][k].first;
                int next_w = graph[j][k].second;

                if (dists[j] != INT_MAX && dists[next_v] > dists[j] + next_w) {
                    dists[next_v] = dists[j] + next_w;

                    if (i == N) {
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
        dists[i] = INT_MAX;
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
            if (dists[i] == INT_MAX) {
                printf("-1\n");
            } else {
                printf("%d\n", dists[i]);
            }
        }
    }

    return 0;
}