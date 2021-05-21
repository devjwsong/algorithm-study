#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> map;

void mapping(int row, int col, int value) {
    if (value == 1) {
        map[row][col] = 1;
    } else {
        int interval = value/3;
        for (int i=row; i<row+value; i+=interval) {
            for (int j=col; j<col+value; j+=interval) {
                if (i>=(row+value/3) && i<(row+value/3*2) && j>=(col+value/3) && j<(col+value/3*2)) {
                    continue;
                }
                mapping(i, j, value/3);
            }
        }
    }
}

int main() {

    scanf("%d", &N);

    map.assign(N, vector<int> (N, 0));

    mapping(0, 0, N);

    for (int r=0; r<N; ++r) {
        for (int c=0; c<N; ++c) {
            if (map[r][c] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }    

    return 0;
}