#include <iostream>
#include <vector>

using namespace std;


/*
Backtracking with a few tricks.
1. How to represent each area? (board[3*(r/3)+(i/3)][3*(c/3)+(i%3)])
2. How to minimally search the cases? (Using recursion to the solved case)
*/
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int r, int c, char d) {
        for (int i=0; i<9; ++i) {
            if (board[r][i] == d || board[i][c] == d || board[3*(r/3)+(i/3)][3*(c/3)+(i%3)] == d) return false;
        }
        
        return true;
    }
    
    bool solve(vector<vector<char>>& board) {
        for (int r=0; r<9; ++r) {
            for (int c=0; c<9; ++c) {
                if (board[r][c] == '.') {
                    for (char d='1'; d<='9'; ++d) {
                        if (isValid(board, r, c, d)) {
                            board[r][c] = d;
                            if (solve(board)) {
                                return true;
                            } else {
                                board[r][c] = '.';
                            }
                        }    
                    }
                    return false;
                }
            }
        }
        
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};


int main() {

    vector<vector<char>> board;
    for (int r=0; r<9; ++r) {
        vector<char> row;
        for (int c=0; c<9; ++c) {
            char val;
            scanf(" %c", &val);
            row.push_back(val);
        }
        board.push_back(row);
    }

    Solution* sol = new Solution();
    sol->solveSudoku(board);

    for (int r=0; r<9; ++r) {
        for (int c=0; c<9; ++c) {
            printf("%c ", board[r][c]);
        }
        printf("\n");
    }

    return 0;
}