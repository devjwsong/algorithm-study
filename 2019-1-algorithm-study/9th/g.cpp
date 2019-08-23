#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> graph[100];

bool dfs(int i, int j) {
    bool checked[N] = {false, };
    stack<pair<int, int>> s;
    s.push({i, 0});
    checked[i] = true;

    while(1) {
        if (s.empty()) {
            break;
        }

        pair<int, int> cur = s.top();
        s.pop();

        if (cur.first == j && cur.second > 0) {
            return true;
        } else {
            for (int k=0; k<graph[cur.first].size(); ++k) {
                if (!checked[graph[cur.first][k]] || graph[cur.first][k] == j) {
                    s.push({graph[cur.first][k], cur.second+1});
                    checked[graph[cur.first][k]] = true;
                }
            }
        }
    }

    return false;

}

int main() {

    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            int p;
            scanf("%d", &p);

            if (p == 1) {
                graph[i].push_back(j);
            }
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (dfs(i, j)) {
                printf("%d ", 1);
            } else {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }

    return 0;
}