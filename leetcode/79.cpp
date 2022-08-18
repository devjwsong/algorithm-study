#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<bool>> used;
    int rowDirs[4] = {-1, 1, 0, 0};
    int colDirs[4] = {0, 0, -1, 1};

    bool search(vector<vector<char>>& board, string& word, int idx, int row, int col) {
        char letter = board[row][col];
        int n = word.size();

        if (word[idx] != letter || used[row][col]) {
            return false;
        }

        if (idx == n-1) return true;
        bool res = false;
        used[row][col] = true;
        for (int d=0; d<4; ++d) {
            int nextRow = row + rowDirs[d];
            int nextCol = col + colDirs[d];
            if (nextRow >= 0 && nextRow < board.size() && nextCol >= 0 && nextCol < board[0].size()) {
                res = res || search(board, word, idx+1, nextRow, nextCol);
            }
        }
        used[row][col] = false;

        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int r=0; r<m; ++r) {
            used.push_back(vector<bool> (n, false));
        }

        if (word.size() > (m*n)) return false;

        for (int r=0; r<m; ++r) {
            for (int c=0; c<n; ++c) {
                bool found = search(board, word, 0, r, c);
                if (found) return true;
            }
        }
        return false;
    }
};

int main() {

    int m, n;
    scanf("%d %d", &m, &n);

    vector<vector<char>> board;
    for (int r=0; r<m; ++r) {
        vector<char> row;
        for (int c=0; c<n; ++c) {
            char letter;
            scanf(" %c", &letter);
            row.push_back(letter);
        }
        board.push_back(row);
    }

    string word;
    getline(cin >> ws, word);

    Solution *sol = new Solution();
    bool answer = sol->exist(board, word);
    printf("%d\n", answer);

    return 0;
}