#include <iostream>
#include <vector>

using namespace std;

int numTest;
vector<int> results;

int getRow(int value) {
    int row = 1;

    while(1) {
        if (value > row*(row+1)/2) {
            ++row;
            continue;
        }

        if (value >= row*(row+1)/2-(row-1) && value <= row*(row+1)/2) {
            return row;
        }
    }
}

int search(int initial, int prize) {
    int move = 0;
    int current = initial;

    int current_row = getRow(current);
    int prize_row = getRow(prize);

    while(1) {
        if (current == prize) {
            return move;
        }

        if (current_row == prize_row) {

            return move + abs(current-prize);

        } else {

            if (current_row > prize_row) {

                int location = 0; //0: middle, 1: left, 2: right

                if (current == current_row*(current_row+1)/2-(current-1)) {
                    location = 1;
                } else if (current == current_row*(current_row+1)/2) {
                    location = 2;
                }

                if (location == 1) {
                    current -= (current_row-1);
                } else if (location == 2) {
                    current -= current_row;
                } else {
                    if (current - (current_row-1) >= prize) {
                        current -= (current_row-1);
                    } else if (current - current_row <= prize) {
                        current -= current_row;
                    }
                }

                ++move;
                --current_row;

            } else if (current_row < prize_row) {

                if (current + (current_row+1) <= prize) {
                    current += (current_row+1);
                } else if (current + current_row >= prize) {
                    current += current_row;
                }

                ++move;
                ++current_row;
            }

        }
    }
}

int main() {
    scanf("%d", &numTest);

    for (int test=1; test<=numTest; ++test) {
        int initial = 0, prize = 0;
        int result = 0;

        scanf("%d %d", &initial, &prize);

        result = search(initial, prize);

        results.push_back(result);
    }

    for (int test=1; test<=numTest; ++test) {
        printf("#%d %d\n", test, results[test-1]);
    }

    return 0;
}