#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> map;

int memo[500][500];
int dirR[] = {-1, 0, 1, 0};
int dirC[] = {0, 1, 0, -1};

int solve(int r, int c) {

    int count = 0;

    for (int d=0; d<4; ++d) {
        int next_r = r + dirR[d];
        int next_c = c + dirC[d];

        if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < n) {
            if (map[r][c] < map[next_r][next_c]) {
                if (memo[next_r][next_c] == -1) {
                    memo[r][c] = max(memo[r][c], 1 + solve(next_r, next_c));
                } else {
                    memo[r][c] = max(memo[r][c], 1 + memo[next_r][next_c]);
                }
                ++count;
            }
        }
    }

    if (count == 0) {
        return 1;
    } else {
        return memo[r][c];
    }
}

int main() {

    scanf("%d", &n);

    map.assign(n, vector<int> (n, 0));

    for (int r=0; r<n; ++r) {
        for (int c=0; c<n; ++c) {
            scanf("%d", &map[r][c]);
            memo[r][c] = -1;
        }
    }

    int answer = 0;

    for (int r=0; r<n; ++r) {
        for (int c=0; c<n; ++c) {
            int result = solve(r, c);
            answer = max(answer, result);
        }
    }

    printf("%d\n", answer);

    return 0;
}