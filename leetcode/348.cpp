#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    vector<vector<int>> board;
    int size;

    TicTacToe(int n) {
        size = n;
        board.assign(size, vector<int> (size, 0));
    }
    
    int move(int row, int col, int player) {
        board[row][col] = player;

        // Row check.
        int count = 0;
        for (int c=0; c<size; ++c) {
            if (board[row][c] == player) ++count;
        }
        if (count == size) return player;

        // Column check.
        count = 0;
        for (int r=0; r<size; ++r) {
            if (board[r][col] == player) ++count;
        }
        if (count == size) return player;

        // Digonal check.
        if (row == col) {
            int r = 0, c = 0;
            count = 0;
            while (r < size && c < size) {
                if (board[r][c] == player) ++count;
                ++r;
                ++c;
            }
            if (count == size) return player;
        }
        if (row + col == size-1) {
            int r = 0, c = size-1;
            count = 0;
            while (r < size && c >= 0) {
                if (board[r][c] == player) ++ count;
                ++r;
                --c;
            }
            if (count == size) return player;
        }

        return 0;
    }
};
