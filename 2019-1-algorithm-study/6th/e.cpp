#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, X;
vector<int> mnts;

vector<vector<char>> map;

void basic(int i, int j) {
    if (mnts[j] >= i) {
        printf("%c", 35);
    } else{
        printf("%c", 46);
    }
}

int main() {

    scanf("%d %d %d", &N, &M, &X);
    mnts.assign(M+1, 0);

    for (int i=1; i<=M; ++i) {
        scanf("%d", &mnts[i]);
    }

    map.assign(N+1, vector<char> (M+1, '.'));

    for (int i=1; i<=N; ++i) {
        int h = N - i + 1;
        for (int j=1; j<=M; ++j) {
            if (mnts[j] >= h) {
                map[i][j] = '#';
            } else {
                map[i][j] = '.';
            }
        }
    }

    for (int i=1; i<=N; ++i) {
        int h = N - i + 1;
        for (int j=1; j<=M; ++j) {
            if (h == X) {
                if (mnts[j] >= X) {
                    map[i][j] = '*';
                } else {
                    map[i][j] = '-';
                }
            } else {
                if (h < X) {
                    if (map[i][j] == '.') {
                        if (j % 3 == 0) {
                            map[i][j] = '|';
                        }  
                    }
                }
            }
        }
    }

    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    return 0;
}