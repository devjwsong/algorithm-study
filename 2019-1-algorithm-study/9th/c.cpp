#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int a, b;
int m;

vector<int> graph[101];

struct State {
    State(int _num, int _count) {
        num = _num;
        count = _count;
    }

    int num;
    int count;
    vector<bool> checked;
};

int bfs() {
    vector<bool> init_checked (n+1, false);
    queue<struct State> q;

    struct State init (a, 0);
    init.checked = init_checked;
    init.checked[a] = true;
    q.push(init);

    int answer = -1;

    while(1) {
        if (q.empty()) {
            break;
        }

        struct State cur = q.front();
        q.pop();

        if (cur.num == b) {
            answer = cur.count;
            break;
        } else {
            for (int i=0; i<graph[cur.num].size(); ++i) {
                if (!cur.checked[graph[cur.num][i]]) {
                    struct State next (graph[cur.num][i], cur.count+1);
                    next.checked = cur.checked;
                    next.checked[graph[cur.num][i]] = true;
                    q.push(next);
                }
            }
        }
    }

    return answer;
}

int main() {

    scanf("%d", &n);
    scanf("%d %d", &a, &b);
    scanf("%d", &m);

    for (int i=0; i<m; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    printf("%d\n", bfs());

    return 0;
}