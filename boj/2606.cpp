#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
vector<int> graph[101];
bool visited[101];

int dfs(int cur) {
    int ret = 1;

    for (int i=0; i<graph[cur].size(); ++i) {
        if (!visited[graph[cur][i]]) {
            visited[graph[cur][i]] = true;
            ret += dfs(graph[cur][i]);
        }
    }

    return ret;
}

int main() {

    scanf("%d", &N);
    scanf("%d", &M);

    for (int i=0; i<M; ++i) {
        int a,b;
        scanf("%d %d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    visited[1] = true;
    printf("%d\n", dfs(1)-1);

    return 0;
}