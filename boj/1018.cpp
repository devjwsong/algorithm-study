#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
vector<vector<char>> board;

int coloring(int row, int col) {
    int ret = INT_MAX;

    int count = 0;
    for (int r=row; r<row+8; ++r) {
        for (int c=col; c<col+8; ++c) {
            if ((r+c) % 2 == 1) {
                if (board[r][c] != 'W') {
                    ++count;
                }
            } else {
                if (board[r][c] != 'B') {
                    ++count;
                }
            }
        }
    }
    ret = min(ret, count);

    count = 0;
    for (int r=row; r<row+8; ++r) {
        for (int c=col; c<col+8; ++c) {
            if ((r+c) % 2 == 1) {
                if (board[r][c] != 'B') {
                    ++count;
                }
            } else {
                if (board[r][c] != 'W') {
                    ++count;
                }
            }
        }
    }
    ret = min(ret, count);

    return ret;
}

int main() {

    scanf("%d %d", &N, &M);
    getchar();
    board.assign(N, vector<char> (M, ' '));

    for (int r=0; r<N; ++r) {
        for (int c=0; c<M; ++c) {
            scanf("%c", &board[r][c]);
        }
        getchar();
    }

    int answer = INT_MAX;

    for (int r=0; r<=(N-8); ++r) {
        for (int c=0; c<=(M-8); ++c) {
            answer = min(answer, coloring(r, c));
        }
    }

    printf("%d\n", answer);

    return 0;
}