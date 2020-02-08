#include <iostream>
#include <vector>

using namespace std;

int t=0;
vector<int> graph[501];
int gNum = 0;
int marked[501];
bool isCycle = false;

void mark(int cur, int from) {
    marked[cur] = gNum;
    for (int i=0; i<graph[cur].size(); ++i) {
        int next = graph[cur][i];
        if (marked[next] == 0) {
            mark(next, cur);
        } else {
            if (marked[next] == gNum && from != -1 && from != next) {
                isCycle = true;
            }
        }
    }
}

int main() {

    while(1) {
        int n, m;
        scanf("%d %d", &n, &m);

        if (n==0 && m==0) {
            break;
        }

        ++t;

        for (int i=1; i<=m; ++i) {
            int a, b;
            scanf("%d %d", &a, &b);

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        int T = 0;
        for (int i=1; i<=n; ++i) {
            isCycle = false;
            if (marked[i] == 0) {
                ++gNum;
                mark(i, -1);

                if (!isCycle) {
                    ++T;
                }
            }
        }

        if (T == 0) {
            printf("Case %d: No trees.\n", t);
        } else if (T == 1) {
            printf("Case %d: There is one tree.\n", t);
        } else {
            printf("Case %d: A forest of %d trees.\n", t, T);
        }

        for (int i=1; i<=n; ++i) {
            graph[i].clear();
            marked[i] = 0;
        }
        gNum = 0;
        isCycle = false;
    }

    return 0;
}