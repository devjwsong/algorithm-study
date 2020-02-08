#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> map;

int dirR[] = {-1, 0, 1, 0};
int dirC[] = {0, 1, 0, -1};

struct State {
    State(int _r, int _c, int _count) {
        r = _r;
        c = _c;
        count = _count;
    }

    int r;
    int c;
    int count;
};

int bfs() {
    int answer = INT_MAX;
    queue<struct State> q;
    vector<vector<bool>> checked (N+1, vector<bool> (M+1, false));
    
    struct State init (1, 1, 1);
    checked[1][1] = true;
    q.push(init);

    while(1) {
        if (q.empty()) {
            break;
        }

        struct State cur = q.front();
        q.pop();

        if (cur.r == N && cur.c == M) {
            answer = min(answer, cur.count);
        } else {
            for (int d=0; d<4; ++d) {
                int next_r = cur.r + dirR[d];
                int next_c = cur.c + dirC[d];

                if (next_r >= 1 && next_r <= N && next_c >= 1 && next_c <= M) {
                    if (map[next_r][next_c] == 1 && !checked[next_r][next_c]) {
                        struct State next (next_r, next_c, cur.count+1);
                        checked[next_r][next_c] = true;
                        q.push(next);
                    }
                }
            }
        }
    }

    return answer;
}

int main() {

    scanf("%d %d", &N, &M);

    map.assign(N+1, vector<int> (M+1, 0));

    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=M; ++c) {
            int p;
            scanf("%1d", &map[r][c]);
        }
    }

    printf("%d\n", bfs());

    return 0;
}