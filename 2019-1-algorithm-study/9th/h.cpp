#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int N, M;
vector<int> graph[10001];

int dfs(int start) {
    bool checked[N+1] = {false, };
    stack<int> s;
    s.push(start);
    checked[start] = true;

    int count = 1;

    while(1) {
        if (s.empty()) {
            break;
        }

        int cur = s.top();
        s.pop();

        for (int i=0; i<graph[cur].size(); ++i) {
            if (!checked[graph[cur][i]]) {
                s.push(graph[cur][i]);
                checked[graph[cur][i]] = true;
                ++count;
            }
        }
    }

    return count;
}

int main() {

    scanf("%d %d", &N, &M);

    for (int i=0; i<M; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);

        graph[b].push_back(a);
    }

    vector<int> results (N+1, 0);
    int max_val = 0;

    for (int i=1; i<=N; ++i) {
        int result = dfs(i);
        max_val = max(max_val, result);
        results[i] = result;
    }

    for (int i=1; i<=N; ++i) {
        if (results[i] == max_val) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}