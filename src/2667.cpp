#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> map;
vector<vector<int>> groups;
vector<int> nums;

int g_num = 0;

int dir_r[] = {-1, 0, 1, 0};
int dir_c[] = {0, 1, 0, -1};

int dfs(int row, int col) {
    int ret = 0;
    groups[row][col] = g_num;
    ++ret;

    for (int d=0; d<4; ++d) {
        int next_r = row + dir_r[d];
        int next_c = col + dir_c[d];

        if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < N) {
            if (groups[next_r][next_c] == 0 && map[next_r][next_c] != 0) {
                ret += dfs(next_r, next_c);
            }
        }
    }

    return ret;
}

int main() {

    scanf("%d", &N);

    map.assign(N, vector<int> (N, 0));
    groups.assign(N, vector<int> (N, 0));

    for (int r=0; r<N; ++r) {
        for (int c=0; c<N; ++c) {
            scanf("%1d", &map[r][c]);
        }
    }

    for (int r=0; r<N; ++r) {
        for (int c=0; c<N; ++c) {
            if (map[r][c] != 0 && groups[r][c] == 0) {
                ++g_num;
                nums.push_back(dfs(r, c));
            }
        }
    }

    sort(nums.begin(), nums.end());

    int num = nums.size();
    printf("%d\n", num);
    for (int i=0; i<nums.size(); ++i) {
        printf("%d\n", nums[i]);
    }

    return 0;
}