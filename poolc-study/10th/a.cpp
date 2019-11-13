#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int V, E;
int K;
vector<pair<int, int>> graph[20001];
int dists[20001];

const int INF = 1000000;

struct State {
    State(int _num, int _dist) {
        num = _num;
        dist = _dist;
    }

    int num;
    int dist;

    bool operator > (const struct State& other) const {
        return dist > other.dist;
    }
};

void search() {
    priority_queue<struct State, vector<struct State>, greater<struct State>> pq;
    dists[K] = 0;
    struct State init (K, 0);
    pq.push(init);

    while(1) {
        if (pq.empty()) {
            break;
        }

        struct State cur = pq.top();
        pq.pop();

        if (cur.dist == dists[cur.num]) {
            for (int i=0; i<graph[cur.num].size(); ++i) {
                if (dists[graph[cur.num][i].first] >= cur.dist + graph[cur.num][i].second) {
                    dists[graph[cur.num][i].first] = cur.dist + graph[cur.num][i].second;
                    struct State next (graph[cur.num][i].first, dists[graph[cur.num][i].first]);
                    pq.push(next);
                }
            }
        }
    }
}

int main() {

    scanf("%d %d", &V, &E);
    scanf("%d", &K);

    for (int i=1; i<=V; ++i) {
        dists[i] = INF;
    }

    for (int i=0; i<E; ++i) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        graph[a].push_back({b, w});
    }

    search();

    for (int i=1; i<=V; ++i) {
        if (dists[i] == INF) {
            printf("INF\n");
        } else {
            printf("%d\n", dists[i]);
        }
    }

    return 0;
}