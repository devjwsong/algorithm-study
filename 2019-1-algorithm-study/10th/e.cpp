#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, X;
int xToEach[1001];
int eachToX[1001];

vector<pair<int, int>> graph[1001];
vector<pair<int, int>> rGraph[1001];

const int INF = 1000000;

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

void dijkstra(bool reverse) {
    priority_queue<struct State, vector<struct State>, greater<struct State>> pq;
    struct State init (X, 0);
    if (reverse) {
        eachToX[X] = 0;
    } else {
        xToEach[X] = 0;
    }
    pq.push(init);

    while(1) {
        if (pq.empty()) {
            break;
        }

        struct State cur = pq.top();
        pq.pop();

        if (reverse) {
            if (cur.dist == eachToX[cur.v]) {
                for (int i=0; i<rGraph[cur.v].size(); ++i) {
                    if (eachToX[rGraph[cur.v][i].first] > cur.dist + rGraph[cur.v][i].second) {
                        eachToX[rGraph[cur.v][i].first] = cur.dist + rGraph[cur.v][i].second;
                        struct State next (rGraph[cur.v][i].first, eachToX[rGraph[cur.v][i].first]);
                        pq.push(next);
                    }
                }
            }
        } else {
            if (cur.dist == xToEach[cur.v]) {
                for (int i=0; i<graph[cur.v].size(); ++i) {
                    if (xToEach[graph[cur.v][i].first] > cur.dist + graph[cur.v][i].second) {
                        xToEach[graph[cur.v][i].first] = cur.dist + graph[cur.v][i].second;
                        struct State next (graph[cur.v][i].first, xToEach[graph[cur.v][i].first]);
                        pq.push(next);
                    }
                }
            }
        }
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &X);

    for (int i=0; i<M; ++i) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        graph[a].push_back({b, w});
        rGraph[b].push_back({a, w});
    }

    for (int i=1; i<=N; ++i) {
        xToEach[i] = INF;
        eachToX[i] = INF;
    }

    dijkstra(true);
    dijkstra(false);

    int answer = 0;

    for (int i=1; i<=N; ++i) {
        answer = max(answer, eachToX[i]+xToEach[i]);
    }

    printf("%d\n", answer);

    return 0;
}