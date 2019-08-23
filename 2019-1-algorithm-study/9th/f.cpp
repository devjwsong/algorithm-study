#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> cpy;

int dirR[] = {-1, 0, 1, 0};
int dirC[] = {0, 1, 0, -1};

void dfs(int row, int col) {
    stack<pair<int, int>> s;
    s.push({row, col});

    while(1) {
        if (s.empty()) {
            break;
        }

        pair<int, int> cur = s.top();
        s.pop();

        for (int d=0; d<4; ++d) {
            int next_r = cur.first + dirR[d];
            int next_c = cur.second + dirC[d];

            if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M) {
                if (cpy[next_r][next_c] == 0) {
                    cpy[next_r][next_c] = 2;
                    s.push({next_r, next_c});
                }
            }
        }
    }
}

void spread() {
    for (int r=0; r<N; ++r) {
        for (int c=0; c<M; ++c) {
            if (cpy[r][c] == 2) {
                dfs(r, c);
            }
        }
    }
}

int getSafe() {
    int count = 0;

    for (int r=0; r<N; ++r) {
        for (int c=0; c<M; ++c) {
            if (cpy[r][c] == 0) {
                ++count;
            }
        }
    }

    return count;
}

int main() {

    scanf("%d %d", &N, &M);

    map.assign(N, vector<int> (M, 0));

    vector<pair<int, int>> spots;
    vector<int> idxs;

    for (int r=0; r<N; ++r) {
        for (int c=0; c<M; ++c) {
            scanf("%d", &map[r][c]);

            if (map[r][c] == 0) {
                spots.push_back({r, c});
            }
        }
    }

    for (int i=0; i<spots.size(); ++i) {
        if (i < spots.size()-3) {
            idxs.push_back(0);
        } else {
            idxs.push_back(1);
        }
    }

    int answer = 0;

    do {
        cpy = map;
        for (int i=0; i<idxs.size(); ++i) {
            if (idxs[i] == 1) {
                pair<int, int> spot = spots[i];
                cpy[spot.first][spot.second] = 1;
            }
        }

        spread();
        answer = max(answer, getSafe());
    } while(next_permutation(idxs.begin(), idxs.end()));

    printf("%d\n", answer);

    return 0;
}