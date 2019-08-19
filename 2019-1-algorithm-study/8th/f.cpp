#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, K;
vector<vector<int>> map;
vector<vector<bool>> checked;

int dirR[] = {-1, 0, 1, 0};
int dirC[] = {0, 1, 0, -1};

struct State {
    State (int _r, int _c, int _count) {
        r = _r;
        c = _c;
        count = _count;
    }

    int r;
    int c;
    int count;
};

bool dfs(int group, int row, int col) {
    stack<struct State> s;
    struct State init (row, col, 1);
    checked[row][col] = true;
    s.push(init);

    stack<pair<int, int>> erase;

    while(1) {
        if (s.empty()) {
            break;
        }

        struct State cur = s.top();
        s.pop();

        erase.push(pair<int, int> (cur.r, cur.c));

        for (int d=0; d<4; ++d) {
            int nextR = cur.r + dirR[d];
            int nextC = cur.c + dirC[d];

            if (nextR >= 0 && nextR < N && nextC >= 0 && nextC < 10) {
                if (map[nextR][nextC] == group && !checked[nextR][nextC]) {
                    struct State next (nextR, nextC, cur.count+1);
                    s.push(next);
                    checked[nextR][nextC] = true;
                }
            }
        }
    }

    if (erase.size() >= K) {
        while(!erase.empty()) {
            pair<int, int> coord = erase.top();
            erase.pop();

            map[coord.first][coord.second] = 0;
        }
        return true;
    } else {
        return false;
    }
}

bool erase() {
    checked.clear();
    checked.assign(N, vector<bool> (10, false));
    int erase_cnt = 0;

    for (int r=0; r<N; ++r) {
        for (int c=0; c<10; ++c) {
            if (map[r][c] != 0 && !checked[r][c]) {
                bool result = dfs(map[r][c], r, c);
                if (result) {
                    ++erase_cnt;
                }
            }
        }
    }

    if (erase_cnt > 0) {
        return true;
    } else {
        return false;
    }
}

void fall() {
    for (int c=0; c<10; ++c) {
        stack<int> values;
        for (int r=0; r<N; ++r) {
            if (map[r][c] != 0) {
                values.push(map[r][c]);
            }
        }

        for (int r=N-1; r>=0; --r) {
            if (!values.empty()) {
                map[r][c] = values.top();
                values.pop();
            } else {
                map[r][c] = 0;
            }
        }
    }
}

int main() {

    scanf("%d %d", &N, &K);

    for (int i=0; i<N; ++i) {
        vector<int> row;
        for (int j=0; j<10; ++j) {
            int p;
            scanf("%1d", &p);
            row.push_back(p);
        }
        map.push_back(row);
    }

    while(1) {
        bool isErased = erase();

        if (!isErased) {
            break;
        } else {
            fall();
        }
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<10; ++j) {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}