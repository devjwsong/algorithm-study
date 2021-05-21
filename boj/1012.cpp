#include <iostream>
#include <vector>

using namespace std;

int T;
int M, N, K;

vector<vector<int>> map;
vector<vector<int>> groups;

int g_num = 0;

int dir_r[] = {-1, 0, 1, 0};
int dir_c[] = {0, 1, 0, -1};

void dfs(int row, int col) {
    groups[row][col] = g_num;

    for (int d=0; d<4; ++d) {
        int next_r = row + dir_r[d];
        int next_c = col + dir_c[d];

        if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M) {
            if (groups[next_r][next_c] == 0 && map[next_r][next_c] != 0) {
                dfs(next_r, next_c);
            }
        }
    }
}

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        scanf("%d %d %d", &M, &N, &K);

        map.assign(N, vector<int> (M, 0));
        groups.assign(N, vector<int> (M, 0));

        for (int i=0; i<K; ++i) {
            int r, c;
            scanf("%d %d", &c, &r);
            map[r][c] = 1;
        }

        for (int r=0; r<N; ++r) {
            for (int c=0; c<M; ++c) {
                if (groups[r][c] == 0 && map[r][c] != 0) {
                    ++g_num;
                    dfs(r, c);
                }
            }
        }

        printf("%d\n", g_num);

        map.clear();
        groups.clear();
        g_num = 0;
    } 

    return 0;
}