#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> graph[1001];

int memo[1001];

void solve(int v) {
    if (graph[v].size() == 0) {
        memo[v] = 0;
    }

    for (int i=0; i<graph[v].size(); ++i) {
        int next = graph[v][i].first;
        int w = graph[v][i].second;

        if (memo[next] == -1) {
            solve(next);
        }

        memo[v] = max(memo[v], memo[next] + w);
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i=0; i<m; ++i) {
        int s, t, c;
        scanf("%d %d %d", &s, &t, &c);

        graph[s].push_back({t, c});
    }

    for (int i=1; i<=n; ++i) {
        memo[i] = -1;
    }

    for (int i=1; i<=n; ++i) {
        solve(i);
    }

    int answer = 0;
    for (int i=1; i<=n; ++i) {
        answer = max(answer, memo[i]);
    }

    printf("%d\n", answer);

    return 0;
}