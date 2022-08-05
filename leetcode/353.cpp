#include <iostream>
#include <vector>

using namespace std;


struct SnakeBody {
    int row;
    int col;


    SnakeBody(int r, int c) {
        row = r;
        col = c;
    }
};


class SnakeGame {
public:
    vector<vector<int>> board;
    vector<vector<int>> foods;
    int foodIdx;
    int score;
    vector<SnakeBody*> snake;

    int rowDirs[4] = {-1, 1, 0, 0};
    int colDirs[4] = {0, 0, -1, 1};

    SnakeGame(int width, int height, vector<vector<int>>& food) {
        board.assign(height, vector<int> (width, 0));
        foods = food;
        foodIdx = 0;
        score = 0;

        SnakeBody* head = new SnakeBody(0, 0);
        snake.push_back(head);
        board[0][0] = 1;
        board[foods[foodIdx][0]][foods[foodIdx][1]] = 2;
    }

    bool isHitByWall(int numRows, int numCols, int r, int c) {
        return r < 0 || r >= numRows || c < 0 || c >= numCols;
    }

    bool isHitBySelf(int r, int c, bool newBody) {
        if (board[r][c] == 1) {
            if (r == snake[snake.size()-1]->row && c == snake[snake.size()-1]->col && !newBody) return false;
            return true;
        }

        return false;
    }
    
    int move(string direction) {
        int d = -1;
        if (direction == "U") {
            d = 0;
        } else if (direction == "D") {
            d = 1;
        } else if (direction == "L") {
            d = 2;
        } else if (direction == "R") {
            d = 3;
        }

        int prevRow = -1, prevCol = -1;
        int nextRow = -1, nextCol = -1;
        bool newBody = false;
        for (int i=0; i<snake.size(); ++i) {
            prevRow = snake[i]->row;
            prevCol = snake[i]->col;

            if (i == 0) {
                nextRow = snake[i]->row + rowDirs[d];
                nextCol = snake[i]->col + colDirs[d];
                if (isHitByWall(board.size(), board[0].size(), nextRow, nextCol)) return -1;
                if (board[nextRow][nextCol] == 2) {
                    ++score;
                    ++foodIdx;
                    if (foodIdx < foods.size()) {
                        board[foods[foodIdx][0]][foods[foodIdx][1]] = 2;
                    }
                    newBody = true;
                }
                if (isHitBySelf(nextRow, nextCol, newBody)) return -1;

            }
            board[nextRow][nextCol] = 1;
            snake[i]->row = nextRow;
            snake[i]->col = nextCol;

            nextRow = prevRow;
            nextCol = prevCol;
        }

        if (newBody) {
            SnakeBody* body = new SnakeBody(prevRow, prevCol);
            snake.push_back(body);
        } else {
            board[prevRow][prevCol] = 0;
        }

        return score;
    }
};