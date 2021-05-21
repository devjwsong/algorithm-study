#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int R, C, T;
vector<vector<int>> map;

pair<int, int> upAir;
pair<int, int> downAir;

int dir_r[] = {-1, 0, 1, 0};
int dir_c[] = {0, 1, 0, -1};

void spread() {
    vector<vector<int>> add (R, vector<int> (C, 0));

    for (int r=0; r<R; ++r) {
        for (int c=0; c<C; ++c) {
            int cur = map[r][c];
            int div = cur / 5;

            if (cur != -1) {
                for (int d=0; d<4; ++d) {
                    int next_r = r + dir_r[d];
                    int next_c = c + dir_c[d];

                    if (next_r >=0 && next_r < R && next_c >= 0 && next_c < C) {
                        if (map[next_r][next_c] != -1) {
                            add[next_r][next_c] += div;
                            add[r][c] -= div;
                        } 
                    }
                }
            }
        }
    }

    for (int r=0; r<R; ++r) {
        for (int c=0; c<C; ++c) {
            map[r][c] += add[r][c];
        }
    }
}

void counterwise() {
    stack<pair<int, int>> s;
    pair<int, int> cur = {upAir.first, upAir.second+1};
    int d = 1;

    while(1) {
        if (cur == upAir) {
            break;
        }

        s.push(cur);
        int next_r = cur.first + dir_r[d];
        int next_c = cur.second + dir_c[d];

        if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) {
            d = ((d-1)+4)%4;
            next_r = cur.first + dir_r[d];
            next_c = cur.second + dir_c[d];
        }

        cur = {next_r, next_c};
    }

    cur = s.top();
    s.pop();

    while(!s.empty()) {
        map[cur.first][cur.second] = map[s.top().first][s.top().second];
        cur = s.top();
        s.pop();
    }

    map[cur.first][cur.second] = 0;
}

void clockwise() {
    stack<pair<int, int>> s;
    pair<int, int> cur = {downAir.first, downAir.second+1};
    int d = 1;

    while(1) {
        if (cur == downAir) {
            break;
        }

        s.push(cur);
        int next_r = cur.first + dir_r[d];
        int next_c = cur.second + dir_c[d];

        if (next_r < 0 || next_r >= R || next_c < 0 || next_c >= C) {
            d = (d+1) % 4;
            next_r = cur.first + dir_r[d];
            next_c = cur.second + dir_c[d];
        }

        cur = {next_r, next_c};
    }

    cur = s.top();
    s.pop();

    while(!s.empty()) {
        map[cur.first][cur.second] = map[s.top().first][s.top().second];
        cur = s.top();
        s.pop();
    }

    map[cur.first][cur.second] = 0;
}

int main() {

    scanf("%d %d %d", &R, &C, &T);

    map.assign(R, vector<int> (C, 0));

    bool isUp = true;

    for (int r=0; r<R; ++r) {
        for (int c=0; c<C; ++c) {
            scanf("%d", &map[r][c]);

            if (map[r][c] == -1) {
                if (isUp) {
                    upAir = {r, c};
                    isUp = false;
                } else {
                    downAir = {r, c};
                }
            }
        }
    }

    for (int t=1; t<=T; ++t) {
        spread();
        counterwise();
        clockwise();
    }

    int count = 0;

    for (int r=0; r<R; ++r) {
        for (int c=0; c<C; ++c) {
            if (map[r][c] > 0) {
                count += map[r][c];
            }
        }
    }

    printf("%d\n", count);

    return 0;
}