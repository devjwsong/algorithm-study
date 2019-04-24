#include <iostream>
#include <cmath>

using namespace std;

int N;
int k;
int length;
int padding;

int map[3072][6144];

void draw() {
    for (int row=0; row < N; ++row) {
        for (int col=0; col < length; ++col) {
            if (map[row][col] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

void mapping() {
    int i = 0;
    int row = 0;
    int col = padding;

    while(1) {

        if (i == 0) {
            map[row][col] = 1;
            ++row;
            --col;
            map[row][col] = 1;
            map[row][col+2] = 1;
            ++row;
            --col;
            for (int j=0; j<5; ++j) {
                map[row][col+j] = 1;
            }
            ++row;
            --col;
        } else {
            int prev_length = 5 * pow(2, i-1) + pow(2, i-1) - 1;
            int prev_padding = prev_length / 2;
            int prev_height = 3 * pow(2, i-1);
            for (int r=0; r<prev_height; ++r) {
                for (int c=col+1; c<col+1+prev_length; ++c) {
                    if (map[r][c] == 1) {
                        map[r+prev_height][c-prev_padding-1] = 1;
                        map[r+prev_height][c-prev_padding+prev_length] = 1;
                    }
                }
            }
            row = 3 * pow(2, i);
            col -= (prev_padding+1); 
        }

        if (i == k) {
            break;
        }

        ++i;
    }
}

int main() {

    scanf("%d", &N);

    int cpy = N;

    while(1) {
        if (cpy % 2 != 0) {
            break;
        }

        cpy /= 2;
        ++k;
    }
    
    length = 5 * pow(2, k) + pow(2, k) - 1;
    padding = length/2;

    mapping();
    draw();

    return 0;
}