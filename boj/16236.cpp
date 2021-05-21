#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

int N;
vector<vector<int>> map;
int R, C;
int shark = 2;
int ate;

int count;

int dir_r[] = {-1, 0, 1, 0};
int dir_c[] = {0, 1, 0, -1};

vector<vector<bool>> checked;

struct State {
    State(int _row, int _col, int _moved) {
        row = _row;
        col = _col;
        moved = _moved;
    }

    int row;
    int col;
    int moved;
};

struct State bfs() {
    queue<struct State> q;
    struct State init (R, C, 0);
    q.push(init);

    checked.assign(N, vector<bool> (N, false));
    checked[R][C] = true;

    struct State answer (-1, -1, INT_MAX);

    while(1) {
        if (q.empty()) {
            break;
        }

        struct State cur = q.front();
        q.pop();

        if (map[cur.row][cur.col] < shark && map[cur.row][cur.col] > 0) {
            if (answer.moved > cur.moved) {
                answer = cur;
            } else if (answer.moved == cur.moved) {
                if (answer.row > cur.row) {
                    answer = cur;
                } else if (answer.row == cur.row) {
                    if (answer.col > cur.col) {
                        answer = cur;
                    }
                }
            }
        } else {
            for (int d=0; d<4; ++d) {
                int next_r = cur.row + dir_r[d];
                int next_c = cur.col + dir_c[d];

                if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < N && shark >= map[next_r][next_c] && !checked[next_r][next_c]) {
                    struct State next (next_r, next_c, cur.moved + 1);
                    q.push(next);
                    checked[next_r][next_c] = true;
                }
            }
        }
    }

    checked.clear();

    return answer;
}

bool move() {
    struct State result = bfs();

    if (result.moved == INT_MAX) {
        return false;
    } else {
        int next_r = result.row;
        int next_c = result.col;
        int dist = result.moved;

        map[next_r][next_c] = 9;
        map[R][C] = 0;
        R = next_r;
        C = next_c;
        ++ate;

        if (ate == shark) {
            ++shark;
            ate = 0;
        }

        count += dist;
        return true;
    }
}

int main() {

    scanf("%d", &N);

    map.assign(N, vector<int> (N, 0));
    for (int r=0; r<N; ++r) {
        for (int c=0; c<N; ++c) {
            scanf("%d", &map[r][c]);

            if (map[r][c] == 9) {
                R = r;
                C = c;
            }
        }
    }

    while(1) {
        if (!move()) {
            break;
        }
    }

    printf("%d\n", count);

    return 0;
}