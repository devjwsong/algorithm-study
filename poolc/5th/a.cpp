#include <iostream>
#include <vector>

using namespace std;

int N, K, L;
vector<vector<int>> map;
vector<char> moves;
vector<vector<int>> snake; // 0: r, 1: c, 2: d

int dirR[] = {-1, 0, 1, 0};
int dirC[] = {0, 1, 0, -1};

int changeDir(int d, char c) {
    if (c == 'L') {
        return (d + 4 - 1) % 4;
    } else if (c == 'D') {
        return (d + 1) % 4;
    }
}

vector<int> moveHead() {
    vector<int> nextHead;
    int nextR = snake[0][0] + dirR[snake[0][2]];
    int nextC = snake[0][1] + dirC[snake[0][2]];

    if (nextR < 1 || nextR > N || nextC < 1 || nextC > N) {
        return nextHead;
    } else {
        if (map[nextR][nextC] == 2) {
            return nextHead;
        } else {
            nextHead.push_back(nextR);
            nextHead.push_back(nextC);
            nextHead.push_back(snake[0][2]);
            return nextHead;
        }
    }
}

int play() {
    int count = 0;
    snake.push_back(vector<int> {1, 1, 1});
    map[snake[0][0]][snake[0][1]] = 2;

    while(1) {

        ++count;

        vector<vector<int>> nextSnake;
        vector<int> nextHead = moveHead();

        if (nextHead.size() == 0) {
            break;
        }

        bool isApple = false;

        if (map[nextHead[0]][nextHead[1]] == 1) {
            isApple = true;
            map[nextHead[0]][nextHead[1]] = 0;
        } 

        nextSnake.push_back(nextHead);
        for (int i=0; i<snake.size()-1; ++i) {
            nextSnake.push_back(snake[i]);
        }

        if (isApple) {
            nextSnake.push_back(snake[snake.size()-1]);
        }

        for (int i=0; i<snake.size(); ++i) {
            map[snake[i][0]][snake[i][1]] = 0;
        }

        for (int i=0; i<nextSnake.size(); ++i) {
            map[nextSnake[i][0]][nextSnake[i][1]] = 2;
        }

        snake = nextSnake;

        if (moves[count] != '-' && count <= 10000) {
            snake[0][2] = changeDir(snake[0][2], moves[count]);
        }
    }

    return count;
}

int main() {

    scanf("%d", &N);
    scanf("%d", &K);
    map.assign(N+1, vector<int> (N+1, 0));

    for (int i=0; i<K; ++i) {
        int r, c;
        scanf("%d %d", &r, &c);
        ++map[r][c];
    }

    scanf("%d", &L);
    moves.assign(10001, '-');

    for (int i=1; i<=L; ++i) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        moves[x] = c;
    }

    printf("%d\n", play());

    return 0;
}