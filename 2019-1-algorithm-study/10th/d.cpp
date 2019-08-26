#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

const int INF = 200000;
int dists[125*125];
int grid[125][125];
vector<pair<int, int>> graph[125*125];

int dir_r[] = {-1, 0, 1, 0};
int dir_c[] = {0, 1, 0, -1};

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
    dists[0] = grid[0][0];
    struct State init (0, dists[0]);
    pq.push(init);

    while(1) {
        if (pq.empty()) {
            break;
        }

        struct State cur = pq.top();
        pq.pop();

        if (dists[cur.v] == cur.dist) {
            for (int i=0; i<graph[cur.v].size(); ++i) {
                if (dists[graph[cur.v][i].first] > cur.dist + graph[cur.v][i].second) {
                    dists[graph[cur.v][i].first] = cur.dist + graph[cur.v][i].second;
                    struct State next (graph[cur.v][i].first, dists[graph[cur.v][i].first]);
                    pq.push(next);
                }
            }
        }
    }
}

int main() {

    int t = 0;

    while(1) {
        scanf("%d", &N);

        if (N == 0) {
            break;
        } else {
            ++t;
        }

        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                scanf("%d", &grid[i][j]);

                dists[i*N+j] = INF;
            }
        }

        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                for (int d=0; d<4; ++d) {
                    int next_r = i + dir_r[d];
                    int next_c = j + dir_c[d];

                    if (next_r >=0 && next_r <N && next_c >=0 && next_c <N) {
                        graph[i*N+j].push_back({next_r*N+next_c, grid[next_r][next_c]});
                    }
                }
            }
        }

        search();

        printf("Problem %d: %d\n", t, dists[N*(N-1) + (N-1)]);

        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j) {
                grid[i][j] = 0;
                dists[i*N+j] = 0;
                graph[i*N+j].clear();
            }
        }
    }

    return 0;
}