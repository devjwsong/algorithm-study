#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rowCheck (9, vector<bool> (9, false));
        vector<vector<bool>> colCheck (9, vector<bool> (9, false));;
        vector<vector<bool>> boxCheck (9, vector<bool> (9, false));;

        for (int r=0; r<9; ++r) {
            for (int c=0; c<9; ++c) {
                if (board[r][c] == '.') continue;
                int boxIdx = (r / 3) + (c / 3) * 3;
                if (rowCheck[r][board[r][c]-'1'] || colCheck[c][board[r][c]-'1'] || boxCheck[boxIdx][board[r][c]-'1']) {
                    return false;
                }
                rowCheck[r][board[r][c]-'1'] = true;
                colCheck[c][board[r][c]-'1'] = true;
                boxCheck[boxIdx][board[r][c]-'1'] = true;
            }
        }

        return true;
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
    bool answer = sol->isValidSudoku(board);
    printf("%d\n", answer);

    return 0;
}