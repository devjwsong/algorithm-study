#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int M, N;
vector<vector<int>> box;

int total = 0;
int done = 0;

int R[] = {-1, 0, 1, 0};
int C[] = {0, 1, 0, -1};

vector<pair<int, int>> start;

struct State {
    State (int _row, int _col, int _day) {
        row = _row;
        col = _col;
        day = _day;
    }

    int row;
    int col;
    int day;
};

int bfs() {
    int result = 0;
    queue<struct State> q;
    for (int i=0; i<start.size(); ++i) {
        struct State init (start[i].first, start[i].second, 0);
        q.push(init);
    }

    while(1) {
        if (q.empty()) {
            break;
        }

        struct State cur = q.front();
        q.pop();

        result = max(result, cur.day);

        for (int d=0; d<4; ++d) {
            int next_r = cur.row + R[d];
            int next_c = cur.col + C[d];

            if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < M) {
                if (box[next_r][next_c] == 0) {
                    box[next_r][next_c] = 1;
                    ++done;
                    struct State next (next_r, next_c, cur.day + 1);
                    q.push(next);
                }
            }
        }
    }

    return result;
}

int main() {

    scanf("%d %d", &M, &N);

    box.assign(N, vector<int> (M, 0));

    for (int r=0; r<N; ++r) {
        for (int c=0; c<M; ++c) {
            scanf("%d", &box[r][c]);

            if (box[r][c] >= 0) {
                ++total;

                if (box[r][c] == 1) {
                    start.push_back({r,c});
                    ++done;
                }
            }
        }
    }

    int answer = 0;

    if (total > done) {
        
        answer = bfs();

        if (total > done) {
            answer = -1;
        }      
    }

    printf("%d\n", answer);

    return 0;
}