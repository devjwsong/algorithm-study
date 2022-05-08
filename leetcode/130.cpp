#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int rowDirs[4] = {-1, 1, 0, 0};
    int colDirs[4] = {0, 0, -1, 1};

    void mark(vector<vector<char>>& board, int r, int c) {
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size()) return;
        if (board[r][c] == 'X' || board[r][c] == '-') return;

        board[r][c] = '-';
        for (int d=0; d<4; ++d) {
            int nextR = r + rowDirs[d];
            int nextC = c + colDirs[d];

            mark(board, nextR, nextC);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for (int r=0; r<m; ++r) {
            if (board[r][0] == 'O') mark(board, r, 0);
            if (board[r][n-1] == 'O') mark(board, r, n-1);
        }

        for (int c=0; c<n; ++c) {
            if (board[0][c] == 'O') mark(board, 0, c);
            if (board[m-1][c] == 'O') mark(board, m-1, c);
        }

        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                if (board[r][c] == '-') board[r][c] = 'O';
            }
        } 
    }
};


int main() {

    int m, n;
    scanf("%d %d", &m, &n);

    vector<vector<char>> board;
    for (int r=0; r<m; ++r) {
        vector<char> row;
        for (int c=0; c<n; ++c) {
            char val;
            scanf(" %c", &val);
            row.push_back(val);
        }
        board.push_back(row);
    }

    Solution* sol = new Solution();
    sol->solve(board);
    for (int r=0; r<m; ++r) {
        for (int c=0; c<n; ++c) {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }

    return  0;
}