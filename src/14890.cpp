#include <iostream>
#include <vector>

using namespace std;

int N, L;
vector<vector<int>> map;

int answer = 0;

bool checkRow(int row) {
    int cur = map[row][0];
    int count = 1;

    for (int c=1; c<N; ++c) {
        if (cur == map[row][c]) {
            ++count;
            cur = map[row][c];
        } else {
            if (abs(cur-map[row][c]) > 1) {
                return false;
            } else {
                if (map[row][c] > cur) {
                    if (count >= L) {
                        cur = map[row][c];
                        count = 1;
                    } else {
                        return false;
                    }
                } else {
                    int flat = 0;
                    for (int j=c; j<c+L; ++j) {
                        if (j >= N) {
                            return false;
                        }

                        if (map[row][c] != map[row][j]) {
                            return false;
                        } else {
                            ++flat;
                        }
                    }

                    if (flat < L) {
                        return false;
                    }

                    c = c+L-1;
                    cur = map[row][c];
                    count = 0;
                }
            }
        }
    }

    return true;
}

bool checkCol(int col) {
    int cur = map[0][col];
    int count = 1;

    for (int r=1; r<N; ++r) {
        if (cur == map[r][col]) {
            ++count;
            cur = map[r][col];
        } else {
            if (abs(cur-map[r][col]) > 1) {
                return false;
            } else {
                if (map[r][col] > cur) {
                    if (count >= L) {
                        cur = map[r][col];
                        count = 1;
                    } else {
                        return false;
                    }
                } else {
                    int flat = 0;
                    for (int j=r; j<r+L; ++j) {
                        if (j >= N) {
                            return false;
                        }

                        if (map[r][col] != map[j][col]) {
                            return false;
                        } else {
                            ++flat;
                        }
                    }

                    if (flat < L) {
                        return false;
                    }

                    r = r+L-1;
                    cur = map[r][col];
                    count = 0;
                }
            }
        }
    }

    return true;
}

void searchHori() {
    for (int r=0; r<N; ++r) {
        if (checkRow(r)) {
            ++answer;
        }
    }
}    

void searchVert() {
    for (int c=0; c<N; ++c) {
        if (checkCol(c)) {
            ++answer;
        }
    }
}

int main() {

    scanf("%d %d", &N, &L);

    map.assign(N, vector<int> (N, 0));

    for (int r=0; r<N; ++r) {
        for (int c=0; c<N; ++c) {
            scanf("%d", &map[r][c]);
        }
    }

    searchHori();
    searchVert();

    printf("%d\n", answer);

    return 0;
}