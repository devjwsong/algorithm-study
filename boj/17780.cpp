#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<vector<int>> map;
vector<vector<int>> state;

struct Unit {
    Unit(int _row, int _col, int _dir) {
        row = _row;
        col = _col;
        dir = _dir;
        top = -1;
        bottom = -1;
    }

    int row;
    int col;
    int dir;
    int top;
    int bottom;
};

vector<struct Unit> units;

int dir_r[] = {0, 0, 0, -1, 1};
int dir_c[] = {0, 1, -1, 0, 0};

int max_num;

void change_order(int cur) {
    swap(units[cur].top, units[cur].bottom);
    if (units[cur].bottom != -1) {
        change_order(units[cur].bottom);
    }
}

int find_top(int cur) {
    if (units[cur].top == -1) {
        return cur;
    } else {
        return find_top(units[cur].top);
    }
}

int find_bottom(int cur) {
    if (units[cur].bottom == -1) {
        return cur;
    } else {
        return find_bottom(units[cur].bottom);
    }
}

int find_num(int cur, int value) {
    if (units[cur].top == -1) {
        return value;
    } else {
        return find_num(units[cur].top, value+1);
    }
}

bool isOut(int row, int col) {
    return !(row >= 1 && row <= N && col >= 1 && col <= N);
}

int change_dir(int dir) {
    if (dir == 1) {
        return 2;
    } else if (dir == 2) {
        return 1;
    } else if (dir == 3) {
        return 4;
    } else if (dir == 4) {
        return 3;
    }
}

void change_row_and_col(int cur, int row, int col) {
    units[cur].row = row;
    units[cur].col = col;

    if (units[cur].top != -1) {
        change_row_and_col(units[cur].top, row, col);
    }
}

void move(int bottom, int prev_r, int prev_c, int next_r, int next_c, bool changed) {
    int original = 0;
    if (changed) {
        original = find_top(bottom);
    } else {
        original = bottom;
    }

    if (state[prev_r][prev_c] == original) {
        state[prev_r][prev_c] = 0;
    }

    if (state[next_r][next_c] == 0) {
        state[next_r][next_c] = bottom;
    } else {
        int cur_top = find_top(state[next_r][next_c]);
        units[cur_top].top = bottom;
        units[bottom].bottom = cur_top;
    }

    change_row_and_col(state[next_r][next_c], next_r, next_c);
}

void move_white(int bottom, int prev_r, int prev_c, int next_r, int next_c) {
    move(bottom, prev_r, prev_c, next_r, next_c, false);
    max_num = max(max_num, find_num(state[next_r][next_c], 1));
}

void move_red(int bottom, int prev_r, int prev_c, int next_r, int next_c) {
    change_order(bottom);
    int idx = find_bottom(bottom);
    move(idx, prev_r, prev_c, next_r, next_c, true);
    max_num = max(max_num, find_num(state[next_r][next_c], 1));
}

int main() {

    scanf("%d %d", &N, &K);

    map.assign(N+1, vector<int> (N+1, 0));
    state.assign(N+1, vector<int> (N+1, 0));

    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=N; ++c) {
            scanf("%d", &map[r][c]);
        }
    }

    struct Unit init (0, 0, 0);
    units.assign(K+1, init);
    for (int i=1; i<=K; ++i) {
        scanf("%d %d %d", &units[i].row, &units[i].col, &units[i].dir);
        state[units[i].row][units[i].col] = i;
    }

    int count = 0;
    while(1) {
        // if (count <= 7) {
        //     cout<<"--------------------"<<endl;
        //     for (int r=1; r<=N; ++r) {
        //         for (int c=1; c<=N; ++c) {
        //             cout<<state[r][c]<<" ";
        //         }
        //         cout<<endl;
        //     }

        //     for (int r=1; r<=N; ++r) {
        //         for (int c=1; c<=N; ++c) {
        //             if (state[r][c] > 0) {
        //                 int cur = state[r][c];
        //                 while(1) {
        //                     cout<<"("<<cur<<", "<<units[cur].row<<", "<<units[cur].col<<", "<<units[cur].dir<<", "<<units[cur].top<<", "<<units[cur].bottom<<") ";
        //                     if (units[cur].top == -1) {
        //                         break;
        //                     } else {
        //                         cur = units[cur].top;
        //                     }
        //                 }
        //                 cout<<endl;
        //             }
        //         }
        //     }
        // }
        
        if (count > 1000) {
            count = -1;
            break;
        }

        max_num = 0;

        for (int i=1; i<=K; ++i) {
            if (units[i].bottom != -1) {
                continue;
            }

            int next_r = units[i].row + dir_r[units[i].dir];
            int next_c = units[i].col + dir_c[units[i].dir];

            if (units[i].bottom != -1) {
                int bottom = units[i].bottom;
                units[bottom].top = -1;
                units[i].bottom = -1;
            }

            if (isOut(next_r, next_c) || map[next_r][next_c] == 2) {
                units[i].dir = change_dir(units[i].dir);

                int re_next_r = units[i].row + dir_r[units[i].dir];
                int re_next_c = units[i].col + dir_c[units[i].dir];

                if (isOut(re_next_r, re_next_c) || map[re_next_r][re_next_c] == 2) {
                    move_white(i, units[i].row, units[i].col, units[i].row, units[i].col);
                } else {
                    if (map[re_next_r][re_next_c] == 0) {
                        move_white(i, units[i].row, units[i].col, re_next_r, re_next_c);
                    } else {
                        move_red(i, units[i].row, units[i].col, re_next_r, re_next_c);
                    }
                }
            } else {
                if (map[next_r][next_c] == 0) {
                    move_white(i, units[i].row, units[i].col, next_r, next_c);
                } else if (map[next_r][next_c] == 1) {  
                    move_red(i, units[i].row, units[i].col, next_r, next_c);
                }
            }
        }

        ++count;

        if (max_num >= 4) {
            break;
        }
    }

    printf("%d\n", count);

    return 0;
}