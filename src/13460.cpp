#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

int N, M;
vector<vector<char>> map;

pair<int, int> R;
pair<int, int> B;
pair<int, int> O;

int dirR[] = {-1, 0, 1, 0};
int dirC[] = {0, 1, 0, -1};

struct State {
    State(int _count, pair<int, int> _red, pair<int, int> _blue) {
        count = _count;
        red = _red;
        blue = _blue;
    }

    int count;
    pair<int, int> red;
    pair<int, int> blue;
};

pair<int, int> move(pair<int, int> start, int d, pair<int, int> another) {
    int curR = start.first;
    int curC = start.second;

    while(1) {
        int nextR = curR + dirR[d];
        int nextC = curC + dirC[d];

        if (nextR == O.first && nextC == O.second) {
            return pair<int, int> (O.first, O.second);
        } else if (map[nextR][nextC] == '#' || (nextR == another.first && nextC == another.second)) {
            return pair<int, int> (curR, curC);
        } else {
            curR = nextR;
            curC = nextC;
        }
    }
}

int bfs() {
    queue<struct State> q;

    struct State init(0, R, B);
    q.push(init);

    int answer = INT_MAX;

    while(1) {
        if (q.empty()) {
            if (answer == INT_MAX) {
                answer = -1;
            }
            break;
        }

        struct State cur = q.front();
        q.pop();

        if (cur.count <= 10) {
            if (cur.blue == O) {
                continue;
            } else {
                if (cur.red == O) {
                    if (cur.count <= answer) {
                        answer = cur.count;
                        break;
                    }
                } else {
                    for (int d=0; d<4; ++d) {
                        pair<int, int> nextRed;
                        pair<int, int> nextBlue;
                        if (d == 0) {
                            if (cur.red.first < cur.blue.first) {
                                nextRed = move(cur.red, d, pair<int, int> (-1, -1));
                                nextBlue = move(cur.blue, d, nextRed);
                            } else {
                                nextBlue = move(cur.blue, d, pair<int, int> (-1, -1));
                                nextRed = move(cur.red, d, nextBlue);
                            }
                        } else if (d == 1) {
                            if (cur.red.second < cur.blue.second) {
                                nextBlue = move(cur.blue, d, pair<int, int> (-1, -1));
                                nextRed = move(cur.red, d, nextBlue);
                            } else {
                                nextRed = move(cur.red, d, pair<int, int> (-1, -1));
                                nextBlue = move(cur.blue, d, nextRed);
                            }
                        } else if (d == 2) {
                            if (cur.red.first < cur.blue.first) {
                                nextBlue = move(cur.blue, d, pair<int, int> (-1, -1));
                                nextRed = move(cur.red, d, nextBlue);
                            } else {
                                nextRed = move(cur.red, d, pair<int, int> (-1, -1));
                                nextBlue = move(cur.blue, d, nextRed);
                            }
                        } else if (d == 3) {
                            if (cur.red.second < cur.blue.second) {
                                nextRed = move(cur.red, d, pair<int, int> (-1, -1));
                                nextBlue = move(cur.blue, d, nextRed);
                            } else {
                                nextBlue = move(cur.blue, d, pair<int, int> (-1, -1));
                                nextRed = move(cur.red, d, nextBlue);
                            }
                        }
                        struct State next (cur.count+1, nextRed, nextBlue);
                        q.push(next);
                    }

                }
            }
        }
    }

    return answer;
}

int main() {

    scanf("%d %d", &N, &M);
    getchar();

    map.assign(N, vector<char> (M, '.'));

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            char input;
            scanf("%c", &input);

            if (input == 'R') {
                R = {i, j};
                map[i][j] = '.';
            } else if (input == 'B') {
                B = {i, j};
                map[i][j] = '.';
            } else if (input == 'O') {
                O = {i, j};
                map[i][j] = '.';
            } else {
                map[i][j] = input;
            }
        }
        getchar();
    }

    int answer = bfs();

    printf("%d\n", answer);

    return 0;
}