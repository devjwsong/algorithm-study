#include <iostream>
#include <vector>

using namespace std;

int R, C, M;

int dir_r[] = {0, -1, 1, 0, 0};
int dir_c[] = {0, 0, 0, 1, -1};

struct Shark {
    Shark (int _r, int _c, int _s, int _d, int _z) {
        r = _r;
        c = _c;
        d = _d;
        s = _s;
        z = _z;
    };

    int r;
    int c;
    int d;
    int s;
    int z;
};

vector<struct Shark> sharks;
vector<vector<int>> map;
int answer = 0;

void hunt(int col) {
    for (int r=1; r<=R; ++r) {
        if (map[r][col] != 0) {
            int idx = map[r][col];
            map[r][col] = 0;
            sharks[idx].r = -1;
            sharks[idx].c = -1;
            answer += sharks[idx].z;
            break;
        }
    }
}

void move(int idx) {
    int next_r = sharks[idx].r + sharks[idx].s * dir_r[sharks[idx].d];
    int next_c = sharks[idx].c + sharks[idx].s * dir_c[sharks[idx].d];
    int next_d = sharks[idx].d;

    while(1) {
        if (next_r >= 1 && next_r <= R && next_c >= 1 && next_c <= C) {
            break;
        }

        if (next_d == 1) {
            next_r = 2 - next_r;
            ++next_d;
        } else if (next_d == 2) {
            next_r = 2*R - next_r;
            --next_d;
        } else if (next_d == 3) {
            next_c = 2*C - next_c;
            ++next_d;
        } else if (next_d == 4) {
            next_c = 2 - next_c;
            --next_d;
        }
    }

    

    map[sharks[idx].r][sharks[idx].c] = 0;
    sharks[idx].r = next_r;
    sharks[idx].c = next_c;
    sharks[idx].d = next_d;
}

void mapping() {
    for (int i=1; i<=M; ++i) {
        int r = sharks[i].r;
        int c = sharks[i].c;

        if (r == -1 && c == -1) {
            continue;
        }

        if (map[r][c] == 0) {
            map[r][c] = i;
        } else {
            int other = map[r][c];
            if (sharks[i].z > sharks[other].z) {
                sharks[other].r = -1;
                sharks[other].c = -1;
                map[r][c] = i;
            } else {
                sharks[i].r = -1;
                sharks[i].c = -1;
            }
        }
    }
}

int main() {

    scanf("%d %d %d", &R, &C, &M);

    map.assign(R+1, vector<int> (C+1, 0));
    struct Shark init (-1, -1, -1, -1, -1);
    sharks.assign(M+1, init);

    for (int i=1; i<=M; ++i) {
        int r, c, s, d, z;
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        struct Shark shark (r, c, s, d, z);
        sharks[i] = shark;

        map[r][c] = i;
    }

    int cur_col = 0;

    while(1) {

        ++cur_col;

        if (cur_col > C) {
            break;
        } else {
            hunt(cur_col);
            for (int i=1; i<=M; ++i) {
                if (sharks[i].r != -1 && sharks[i].c != -1) {
                    move(i);
                }
            }
            mapping();
        }
    }

    printf("%d\n", answer);

    return 0;
}