#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, L, R;
vector<vector<int>> map;
vector<vector<int>> checked;

int dirR[] = {-1, 0, 1, 0};
int dirC[] = {0, 1, 0, -1};

void bfs(int row, int col, int num) {
    queue<pair<int, int>> q;
    q.push({row, col});
    checked[row][col] = num;

    while(1) {
        if (q.empty()) {
            break;
        }

        pair<int, int> cur = q.front();
        q.pop();

        for (int d=0; d<4; ++d) {
            int new_r = cur.first + dirR[d];
            int new_c = cur.second + dirC[d];

            if (new_r >= 0 && new_r < N && new_c >= 0 && new_c < N) {
                if (checked[new_r][new_c] == -1) {
                    int diff = abs(map[cur.first][cur.second] - map[new_r][new_c]);
                    if (diff >= L && diff <= R) {
                        q.push({new_r, new_c});
                        checked[new_r][new_c] = num;
                    }
                }
            }
        }
    }
}

int main() {

    scanf("%d %d %d", &N, &L, &R);

    map.assign(N, vector<int> (N, -1));

    for (int r=0; r<N; ++r) {
        for (int c=0; c<N; ++c) {
            scanf("%d", &map[r][c]);
        }
    }

    int move = 0;

    while(1) {

        checked.assign(N, vector<int> (N, -1));

        int num = 0;

        for (int r=0; r<N; ++r) {
            for (int c=0; c<N; ++c) {
                if (checked[r][c] == -1) {
                    bfs(r, c, num);
                    ++num;
                }
            }
        }

        pair<int, int> memo[N*N] = {{0, 0}, };
        int solo = 0;

        for (int r=0; r<N; ++r) {
            for (int c=0; c<N; ++c) {
                int num = checked[r][c];
                memo[num].first += map[r][c];
                ++memo[num].second;
            }
        }

        for (int r=0; r<N; ++r) {
            for (int c=0; c<N; ++c) {
                int num = checked[r][c];
                map[r][c] = (memo[num].first / memo[num].second);

                if (memo[num].second == 1) {
                    ++solo;
                }
            }
        }

        if (solo == N*N) {
            break;
        } else {
            ++move;
        }

        checked.clear();
    }

    printf("%d\n", move);

    return 0;
}