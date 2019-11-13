#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int S, D;

vector<pair<int, int>> graph[500];
vector<pair<int, int>> rGraph[500];
vector<vector<bool>> elim;
int dists[500];

const int INF = 100000000;

struct State {
    State(int _v, int _d) {
        v = _v;
        d = _d;
    }

    int v;
    int d;

    bool operator > (const struct State& other) const {
        return d > other.d;
    };
};

void dijkstra() {
    priority_queue<struct State, vector<struct State>, greater<struct State>> pq;
    struct State init (S, 0);
    pq.push(init);
    dists[S] = 0;

    while(1) {
        if (pq.empty()) {
            break;
        }

        struct State cur = pq.top();
        pq.pop();

        if (cur.d == dists[cur.v]) {
            int u = 0;
            int v = 0;

            for (int i=0; i<graph[cur.v].size(); ++i) {
                if (dists[graph[cur.v][i].first] > cur.d + graph[cur.v][i].second) {
                    if (!elim[cur.v][graph[cur.v][i].first]) {
                        dists[graph[cur.v][i].first] = cur.d + graph[cur.v][i].second;
                        struct State next (graph[cur.v][i].first, dists[graph[cur.v][i].first]);
                        pq.push(next); 
                    }    
                }
            }
        }
    }
}

void eliminate() {
    queue<int> q;
    q.push(D);

    while(1) {
        if (q.empty()) {
            break;
        }

        int cur = q.front();
        q.pop();

        if (cur == S) {
            continue;
        }

        for (int i=0; i<rGraph[cur].size(); ++i) {
            if (dists[rGraph[cur][i].first] + rGraph[cur][i].second == dists[cur]) {
                elim[rGraph[cur][i].first][cur] = true;
                q.push(rGraph[cur][i].first);
            }
        }
    }
    
}

int main() {

    while(1) {
        scanf("%d %d", &N, &M);

        if (N==0 && M==0) {
            break;
        }

        elim.assign(N, vector<bool> (N, false));

        scanf("%d %d", &S, &D);

        for (int i=0; i<N; ++i) {
            dists[i] = INF;
        }

        for (int i=0; i<M; ++i) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);

            graph[u].push_back({v, p});
            rGraph[v].push_back({u, p});
        }

        dijkstra();
        eliminate();

        for (int i=0; i<N; ++i) {
            dists[i] = INF;
        }

        dijkstra();

        if (dists[D] == INF) {
            printf("%d\n", -1);
        } else {
            printf("%d\n", dists[D]);
        }

        for (int i=0; i<N; ++i) {
            dists[i] = 0;
            graph[i].clear();
            rGraph[i].clear();
        }

        elim.clear();
    }

    return 0;
}