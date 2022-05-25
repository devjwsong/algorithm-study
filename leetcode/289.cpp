#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    /*
    0 -> 0: 0, 1 -> 1: 1
    0 -> 1: 2, 1 -> 0: 3
    */
    int rowDirs[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int colDirs[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    bool isValid(int m, int n, int r, int c) {
        return r >= 0 && r < m && c >= 0 && c < n;
    }

    int convert(vector<vector<int>>& board, int r, int c) {
        int m = board.size(), n = board[0].size();
        int res = 0;
        int count = 0;
        for (int d=0; d<8; ++d) {
            int nextR = r + rowDirs[d];
            int nextC = c + colDirs[d];
            if (isValid(m, n, nextR, nextC)) {
                if (board[nextR][nextC] == 1 || board[nextR][nextC] == 3) ++count;
            }
        }

        if (board[r][c] == 0) {
            if (count == 3) return 2;
            return 0;
        } else {
            if (count < 2) {
                return 3;
            } else if (count <= 3) {
                return 1;
            } else {
                return 3;
            }
        }
    }

    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                board[r][c] = convert(board, r, c);
            }
        }

        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (board[r][c] == 2) {
                    board[r][c] = 1;
                } else if (board[r][c] == 3) {
                    board[r][c] = 0;
                }
            }
        }
    }
};


int main() {

    int m, n;
    scanf("%d %d", &m, &n);

    vector<vector<int>> board;
    for (int r=0; r<m; ++r) {
        vector<int> row;
        for (int c=0; c<n; ++c) {
            int val;
            scanf(" %d", &val);
            row.push_back(val);
        }
        board.push_back(row);
    }

    Solution* sol = new Solution();
    sol->gameOfLife(board);
    for (int r=0; r<m; ++r) {
        for (int c=0; c<n; ++c) {
            printf("%d ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}