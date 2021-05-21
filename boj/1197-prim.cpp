#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E;
vector<pair<int, int>> graph[10001];

bool visited[10001];

int prim(int start) {
    int ret = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, start});

    while(1) {
        if (pq.empty()) {
            break;
        }

        pair<int, int> cur = pq.top();
        pq.pop();

        if (visited[cur.second]) {
            continue;
        }

        visited[cur.second] = true;
        ret += cur.first;

        for (int i=0; i<graph[cur.second].size(); ++i) {
            int next_v = graph[cur.second][i].second;
            if (!visited[next_v]) {
                pq.push(graph[cur.second][i]);
            }
        }
    }

    return ret;
}

int main() {

    scanf("%d %d", &V, &E);

    for (int e=1; e<=E; ++e) {
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);

        graph[a].push_back({w, b});
        graph[b].push_back({w, a});
    }

    printf("%d\n", prim(1));

    return 0;
}