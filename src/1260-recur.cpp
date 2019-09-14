#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M, V;
vector<int> graph[1001];
bool dfs_visited[1001];

void dfs(int cur) {
    printf("%d ", cur);
    for (int i=0; i<graph[cur].size(); ++i) {
        if (!dfs_visited[graph[cur][i]]) {
            dfs_visited[graph[cur][i]] = true;
            dfs(graph[cur][i]);
        }
    }
}

void bfs() {
    bool visited[N+1] = {false, };
    queue<int> q;
    q.push(V);
    visited[V] = true;
    printf("%d ", V);

    while(1) {
        if (q.empty()) {
            break;
        }

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); ++i) {
            if (!visited[graph[cur][i]]) {
                q.push(graph[cur][i]);
                visited[graph[cur][i]] = true;
                printf("%d ", graph[cur][i]);
            }
        }
    }

    printf("\n");
}

int main() {

    scanf("%d %d %d", &N, &M, &V);

    for (int i=0; i<M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i=1; i<=N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs_visited[V] = true;
    dfs(V);
    printf("\n");

    bfs();

    return 0;
}