#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int V, E;
int K;
vector<pair<int, int>> graph[20001];
int dists[20001];

struct State {
    State(int _v, int _dist) {
        v = _v;
        dist = _dist;
    }

    int v;
    int dist;

    bool operator > (const struct State& other) const {
        return dist > other.dist;
    }
};

void search() {
    priority_queue<struct State, vector<struct State>, greater<struct State>> pq;
    struct State init (K, 0);
    pq.push(init);
    dists[K] = 0;

    while(1) {
        if (pq.empty()) {
            break;
        }

        struct State cur = pq.top();
        pq.pop();

        if (cur.dist == dists[cur.v]) {
            for (int i=0; i<graph[cur.v].size(); ++i) {
                if (dists[graph[cur.v][i].first] >= cur.dist + graph[cur.v][i].second) {
                    dists[graph[cur.v][i].first] = cur.dist + graph[cur.v][i].second;
                    struct State next (graph[cur.v][i].first, dists[graph[cur.v][i].first]);
                    pq.push(next);
                }
            }
        }
    }
}

int main() {

    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    for (int i=0; i<E; ++i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u].push_back({v, w});
    }

    for (int i=1; i<=V; ++i) {
        dists[i] = INT_MAX;
    }

    search();

    for (int i=1; i<=V; ++i) {
        if (dists[i] == INT_MAX) {
            printf("INF\n");
        } else {
            printf("%d\n", dists[i]);
        }
    }

    return 0;
}