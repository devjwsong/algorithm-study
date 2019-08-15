#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
char map[1000][1000];
int group[1000][1000];

int dir_row[] = {-1, 0, 1, 0};
int dir_col[] = {0, 1, 0, -1};

int group_num = 1;

struct State {
    State(int _cur_r, int _cur_c) {
        cur_r = _cur_r;
        cur_c = _cur_c;
    }

    int cur_r;
    int cur_c;
};

pair<int, int> grouping(int row, int col) {
    int area = 0;
    int peri = 0;

    queue<struct State> q;
    struct State init (row, col);
    q.push(init);

    while(1) {
        if (q.empty()) {
            break;
        }

        struct State cur = q.front();
        q.pop();

        if (group[cur.cur_r][cur.cur_c] > 0) {
            continue;
        }

        group[cur.cur_r][cur.cur_c] = group_num;
        area += 1;

        for (int d=0; d<4; ++d) {
            int next_r = cur.cur_r + dir_row[d];
            int next_c = cur.cur_c + dir_col[d];

            if (next_r < 0 || next_r >= N || next_c < 0 || next_c >= N) {
                peri += 1;
            } else {
                if (map[next_r][next_c] == '#') {
                    if (group[next_r][next_c] > 0) {
                        continue;
                    }

                    struct State next (next_r, next_c);
                    q.push(next);
                } else {
                    peri += 1;
                }
            }
        }
    }
    return pair<int, int> (area, peri);
}

int main() {
    scanf("%d", &N);
    getchar();

    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            scanf("%c", &map[i][j]);
        }
        getchar();
    }

    int max_area = 0;
    int max_peri = 0;

    for (int r=0; r<N; ++r) {
        for (int c=0; c<N; ++c) {
            if (map[r][c] == '#' && group[r][c] == 0) {
                pair<int, int> result = grouping(r, c);
                ++group_num;

                if (result.first >= max_area) {
                    max_area = result.first;
                    max_peri = result.second;
                }
            } 
        }
    }

    printf("%d %d\n", max_area, max_peri);

    return 0;
}