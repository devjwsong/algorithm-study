#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
vector<int> people;

struct State {
    State() {
        i = 0;
        j = 0;
        k = 0;
    }

    State(int _i, int _j, int _k) {
        i = _i;
        j = _j;
        k = _k;
    }

    int i, j, k;
};

int total[101][11][101];
int dirt[101][11][101];
struct State trace[101][11][101];

const int INF = 10000000;

vector<int> clean_day;

void follow(int i, int j, int k) {
    if (i == 0) {
        return;
    } else {
        struct State prev;
        prev = trace[i][j][k];
        if (prev.k != k) {
            clean_day.push_back(k);
        }
        follow(prev.i, prev.j, prev.k);
    }
}

int main() {

    scanf("%d %d", &N, &M);
    people.assign(N+1, 0);

    for (int i=1; i<=N; ++i) {
        scanf("%d", &people[i]);
    }

    for (int i=1; i<=N; ++i) {
        for (int j=0; j<=M; ++j) {
            for (int k=0; k<=N; ++k) {
                total[i][j][k] = INF;
            }
        }
    }

    for (int i=1; i<=N; ++i) {
        for (int j=0; j<i; ++j) {
            if (j <= M) {
                if (j==0) {
                    int add = (dirt[i-1][j][0] + people[i-1]) * people[i];
                    if (total[i][j][0] > total[i-1][j][0] + add) {
                        total[i][j][0] = total[i-1][j][0] + add;
                        dirt[i][j][0] = dirt[i-1][j][0] + people[i-1];
                        struct State state (i-1, j, 0);
                        trace[i][j][0] = state;
                    }
                } else {
                    for (int k=1; k<i; ++k) {
                        int add = (dirt[i-1][j][k] + people[i-1]) * people[i];
                        if (total[i][j][k] > total[i-1][j][k] + add) {
                            total[i][j][k] = total[i-1][j][k] + add;
                            dirt[i][j][k] = dirt[i-1][j][k] + people[i-1];
                            struct State state (i-1, j, k);
                            trace[i][j][k] = state;
                        }
                    }
                }
            }   
        }

        for (int j=1; j<=i; ++j) {
            for (int k=0; k<i; ++k) {
                if (j <= M) {
                    if (total[i][j][i] > total[i-1][j-1][k]) {
                        total[i][j][i] = total[i-1][j-1][k];
                        dirt[i][j][i] = 0;
                        struct State state (i-1, j-1, k);
                        trace[i][j][i] = state;
                    }
                }
            }
        }
    }

    int answer = INF;
    int min_k = 0;
    for (int k=1; k<=N; ++k) {
        if (answer > total[N][M][k]) {
            answer = total[N][M][k];
            min_k = k;
        }
    }

    follow(N, M, min_k);

    printf("%d\n", answer);
    for (int i=clean_day.size()-1; i>=0; --i) {
        if (clean_day[i]-1 > 0) {
            printf("%d ", clean_day[i]-1);
        }
    }
    printf("\n");

    return 0;
}