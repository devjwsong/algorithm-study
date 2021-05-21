#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int N, M;
int map[50][50];
int cpy[50][50];
int times[50][50];

vector<pair<int, int>> viruses;
vector<int> idxs;
pair<int, int> activated[10];

int dir_r[] = {-1, 0, 1, 0};
int dir_c[] = {0, 1, 0, -1};

int num_zero = 0;

struct State {
    State (int _row, int _col, int _time) {
        row = _row;
        col = _col;
        time = _time;
    }

    int row;
    int col;
    int time;
};

// int isFinished() {
//     int ret = 0;

//     for (int r=0; r<N; ++r) {
//         for (int c=0; c<N; ++c) {
//             if (times[r][c] == INT_MAX) {
//                 return -1;
//             } else {
//                 ret = max(ret, times[r][c]);
//             }
//         }
//     }

//     return ret;
// }

int spread() {
    int result = 0;
    int count = 0;

    queue<struct State> q;
    for (int i=0; i<M; ++i) {
        struct State init (activated[i].first, activated[i].second, 0);
        q.push(init);
    }

    while(1) {
        if (q.empty()) {
            return -1;
        }

        // int ret = isFinished();
        if (count == num_zero) {
            break;
        } else {
            struct State cur = q.front();
            q.pop();
            
            for (int d=0; d<4; ++d) {
                int next_r = cur.row + dir_r[d];
                int next_c = cur.col + dir_c[d];

                if (next_r >= 0 && next_r < N && next_c >= 0 && next_c < N) {
                    if (times[next_r][next_c] == -2 || times[next_r][next_c] == -3) {
                        if (times[next_r][next_c] == -2) {
                            result = max(result, cur.time+1);
                            ++count;
                        }

                        times[next_r][next_c] = cur.time+1;
                        struct State next (next_r, next_c, cur.time+1);
                        q.push(next);
                    }
                }
            }
        }
    }

    return result;
}

int main() {

    scanf("%d %d", &N, &M);

    for (int r=0; r<N; ++r) {
        for (int c=0; c<N; ++c) {
            scanf("%d", &map[r][c]);

            if (map[r][c] == 2) {
                viruses.push_back({r, c});
            }
            
            if (map[r][c] == 0) {
                ++num_zero;
            }
        }
    }

    int num_viruses = viruses.size();
    idxs.assign(num_viruses, 0);
    for (int i=num_viruses-1; i>=num_viruses-M; --i) {
        idxs[i] = 1;
    }

    int answer = INT_MAX;

    do {
        for (int r=0; r<N; ++r) {
            for (int c=0; c<N; ++c) {
                if (map[r][c] == 0) {
                    times[r][c] = -2;
                } else if (map[r][c] == 1) {
                    times[r][c] = -1;
                } else if (map[r][c] == 2) {
                    times[r][c] = -3;
                }
            }
        }

        int act_i = 0;
        for (int i=0; i<idxs.size(); ++i) {
            if (idxs[i] == 1) {
                pair<int, int> virus = viruses[i];
                activated[act_i] = virus;
                ++act_i;
                times[virus.first][virus.second] = 0;
            }
        }

        // cout<<"Activated: ";
        // for (int i=0; i<M; ++i) {
        //     cout<<"("<<activated[i].first<<", "<<activated[i].second<<") ";
        // }
        // cout<<endl;

        int result = spread();
        if (result >= 0) {
            answer = min(answer, result);
        }

        // for (int r=0; r<N; ++r) {
        //     for (int c=0; c<N; ++c) {
        //         cout<<times[r][c]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<"-------------------------"<<endl;

    } while(next_permutation(idxs.begin(), idxs.end()));

    if (answer == INT_MAX) {
        printf("-1\n");
    } else {
        printf("%d\n", answer);
    }

    return 0;
}