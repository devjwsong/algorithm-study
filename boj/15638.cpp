#include <iostream>
#include <vector>
#include <stack>
#include <climits>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<struct Cam> cams;

int dirR[] = {-1, 0, 1, 0};
int dirC[] = {0, 1, 0, -1};

struct Cam {
    Cam (int _num, int _row, int _col) {
        num = _num;
        row = _row;
        col = _col;
    }

    int num;
    int row;
    int col;
};

struct State {
    State (int _idx) {
        idx = _idx;
    }

    int idx;
    vector<int> rots;
};

void drawLine(vector<vector<int>>& cpy, int r, int c, int d) {
    int curR = r;
    int curC = c;

    while(1) {
        if (curR < 0 || curR >= N || curC < 0 || curC >= M) {
            break;
        } else {
            if (cpy[curR][curC] == 6) {
                break;
            } else {
                if (cpy[curR][curC] == 0) {
                    cpy[curR][curC] = 7;
                }
                curR += dirR[d];
                curC += dirC[d];
            }
        }
    }
}

void spread(vector<vector<int>>& cpy, vector<int> rots) {
    for (int i=0; i<rots.size(); ++i) {
        int cam_num = cams[i].num;
        int rot_num = rots[i];

        if (cam_num == 1) {
            drawLine(cpy, cams[i].row, cams[i].col, rot_num);
        } else if (cam_num == 2) {
            if (rot_num == 0) {
                drawLine(cpy, cams[i].row, cams[i].col, 0);
                drawLine(cpy, cams[i].row, cams[i].col, 2);
            } else if (rot_num == 1) {
                drawLine(cpy, cams[i].row, cams[i].col, 1);
                drawLine(cpy, cams[i].row, cams[i].col, 3);
            }
        } else if (cam_num == 3) {
            int second = (rot_num + 1) % 4;
            drawLine(cpy, cams[i].row, cams[i].col, rot_num);
            drawLine(cpy, cams[i].row, cams[i].col, second);
        } else if (cam_num == 4) {
            int second = (rot_num + 1) % 4;
            int third = (second + 1) % 4;
            drawLine(cpy, cams[i].row, cams[i].col, rot_num);
            drawLine(cpy, cams[i].row, cams[i].col, second);
            drawLine(cpy, cams[i].row, cams[i].col, third);
        } else if (cam_num == 5) {
            drawLine(cpy, cams[i].row, cams[i].col, 0);
            drawLine(cpy, cams[i].row, cams[i].col, 1);
            drawLine(cpy, cams[i].row, cams[i].col, 2);
            drawLine(cpy, cams[i].row, cams[i].col, 3);
        }
    }
}


int getArea(vector<vector<int>> cpy) {
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

int dfs() {
    int answer = INT_MAX;

    stack<struct State> s;
    struct State init (-1);
    s.push(init);

    while(1) {
        if (s.empty()) {
            break;
        }

        struct State cur = s.top();
        s.pop();

        if (cur.idx == cams.size()-1) {
            vector<vector<int>> cpy = map;
            spread(cpy, cur.rots);
            answer = min(answer, getArea(cpy));
        } else {
            int cam_num = cams[cur.idx + 1].num;
            if (cam_num == 1 || cam_num == 3 || cam_num == 4) {
                for (int d=0; d<4; ++d) {
                    struct State next(cur.idx + 1);
                    next.rots = cur.rots;
                    next.rots.push_back(d);
                    s.push(next);
                }
            } else if (cam_num == 2) {
                for (int d=0; d<2; ++d) {
                    struct State next(cur.idx + 1);
                    next.rots = cur.rots;
                    next.rots.push_back(d);
                    s.push(next);
                }
            } else if (cam_num == 5) {
                struct State next(cur.idx + 1);
                next.rots = cur.rots;
                next.rots.push_back(0);
                s.push(next);
            }
        }
    }

    return answer;
}

int main() {

    scanf("%d %d", &N, &M);

    map.assign(N, vector<int> (M, 0));

    for (int r=0; r<N; ++r) {
        for (int c=0; c<M; ++c) {
            scanf("%d", &map[r][c]);

            if (map[r][c] >= 1 && map[r][c] <= 5) {
                struct Cam cam (map[r][c], r, c);
                cams.push_back(cam);
            }
        }
    }

    printf("%d\n", dfs());

    return 0;
}