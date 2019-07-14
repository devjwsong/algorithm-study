#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
int q;

vector<int> graph[501];
int dist[501];

void bfs() {
    queue<int> q;
    
    for (int i=1; i<=n; ++i) {
        dist[i] = INT_MAX;
    }

    q.push(1);
    dist[1] = 0;

    while(1) {
        if (q.empty()) {
            break;
        }

        int cur = q.front();
        q.pop();

        for (int i=0; i<graph[cur].size(); ++i) {
            if (dist[graph[cur][i]] == INT_MAX) {
                dist[graph[cur][i]] = dist[cur] + 1;
                q.push(graph[cur][i]);
            }
        }
    }

    for (int i=1; i<=n; ++i) {
        if (dist[i] == INT_MAX) {
            printf("-1 ");
        } else {
            printf("%d ", dist[i]);
        }
    }
    printf("\n");
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i=0; i<m; ++i) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);

        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }

    scanf("%d", &q);

    for (int i=0; i<q; ++i) {
        int flag, c1, c2;
        scanf("%d %d %d", &flag, &c1, &c2);

        if (flag == 1) {
            graph[c1].push_back(c2);
            graph[c2].push_back(c1);
        } else if (flag == 2) {
            graph[c1].erase(find(graph[c1].begin(), graph[c1].end(), c2));
            graph[c2].erase(find(graph[c2].begin(), graph[c2].end(), c1));
        }

        bfs();
    }

    return 0;
}