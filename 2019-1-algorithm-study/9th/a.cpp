#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<int> graph[1001];

void dfs() {
    bool dfs_checked[N+1] = {false, };
    stack<int> s;
    s.push(V);

    while(1) {
        if (s.empty()) {
            break;
        }

        int cur = s.top();
        s.pop();

        if (dfs_checked[cur]) {
            continue;
        }

        printf("%d ", cur);
        dfs_checked[cur] = true;

        for (int i=0; i<graph[cur].size(); ++i) {
            if (!dfs_checked[graph[cur][i]]) {
                s.push(graph[cur][i]);
            }
        }
    }
}

void bfs() {
    bool bfs_checked[N+1] = {false, };
    queue<int> q;
    q.push(V);

    while(1) {
        if (q.empty()) {
            break;
        }

        int cur = q.front();
        q.pop();

        if (bfs_checked[cur]) {
            continue;
        }

        printf("%d ", cur);
        bfs_checked[cur] = true;

        for (int i=0; i<graph[cur].size(); ++i) {
            if (!bfs_checked[graph[cur][i]]) {
                q.push(graph[cur][i]);
            }
        }
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &V);

    for (int i=1; i<=M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i=1; i<=N; ++i) {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    dfs();
    printf("\n");

    for (int i=1; i<=N; ++i) {
        sort(graph[i].begin(), graph[i].end());
    }

    bfs();
    printf("\n");

    return 0;
}