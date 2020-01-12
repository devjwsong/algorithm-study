#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M, K;
vector<vector<int>> A;
vector<vector<vector<int>>> map;
vector<vector<int>> food;

struct Tree {
    Tree (int _row, int _col, int _age) {
        row = _row;
        col = _col;
        age = _age;
    }

    int row;
    int col;
    int age;
};

vector<struct Tree> deads;
vector<struct Tree> mothers;

int dir_r[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dir_c[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void spring() {
    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=N; ++c) {
            if (map[r][c].size() == 0) {
                continue;
            }

            vector<int> cpy;
            sort(map[r][c].begin(), map[r][c].end());
            for (int i=0; i<map[r][c].size(); ++i) {
                if (map[r][c][i] <= food[r][c]) {
                    cpy.push_back(map[r][c][i]+1);
                    food[r][c] -= map[r][c][i];

                    if ((map[r][c][i]+1) % 5 == 0) {
                        struct Tree mother (r, c, map[r][c][i]+1);
                        mothers.push_back(mother);
                    }
                } else {
                    struct Tree dead (r, c, map[r][c][i]);
                    deads.push_back(dead);
                }
            }

            map[r][c].clear();

            for (int i=0; i<cpy.size(); ++i) {
                map[r][c].push_back(cpy[i]);
            }
        }
    }
}

void summer() {
    for (int i=0; i<deads.size(); ++i) {
        struct Tree dead = deads[i];
        food[dead.row][dead.col] += dead.age / 2;
    }

    deads.clear();
}

void fall() {
    for (int i=0; i<mothers.size(); ++i) {
        struct Tree mother = mothers[i];

        for (int d=0; d<8; ++d) {
            int next_r = mother.row + dir_r[d];
            int next_c = mother.col + dir_c[d];

            if (next_r >= 1 && next_r <= N && next_c >= 1 && next_c <= N) {
                map[next_r][next_c].push_back(1);
            }
        }
    }

    mothers.clear();
}

void winter() {
    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=N; ++c) {
            food[r][c] += A[r][c];
        }
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &K);

    A.assign(N+1, vector<int> (N+1, 0));
    vector<int> init;
    map.assign(N+1, vector<vector<int>> (N+1, init));
    food.assign(N+1, vector<int> (N+1, 5));
    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=N; ++c) {
            scanf("%d", &A[r][c]);
        }
    }

    for (int i=0; i<M; ++i) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        map[x][y].push_back(z);
    }

    for (int k=1; k<=K; ++k) {
        spring();
        summer();
        fall();
        winter();
    }

    int answer = 0;

    for (int r=1; r<=N; ++r) {
        for (int c=1; c<=N; ++c) {
            answer += map[r][c].size();
        }
    }

    printf("%d\n", answer);

    return 0;
}