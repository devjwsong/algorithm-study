#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M;
vector<int> graph[1001];

int group = 0;
int checked[1001];

void dfs(int start) {
    stack<int> s;
    s.push(start);

    while(1) {
        if (s.empty()) {
            break;
        }

        int cur = s.top();
        s.pop();

        if (checked[cur] > 0) {
            continue;
        } else {
            checked[cur] = group;
            for (int i=0; i<graph[cur].size(); ++i) {
                if (checked[graph[cur][i]] == 0) {
                    s.push(graph[cur][i]);
                }
            }
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);

    for (int i=0; i<M; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i=1; i<=N; ++i) {
        if (checked[i] == 0) {
            ++group;
            dfs(i);
        }
    }

    printf("%d\n", group);

    return 0;
}