#include <iostream>
#include <vector>

using namespace std;

int T = 10;
int len = 8;
vector<vector<char>> map;

bool isPalinHori(int c1, int c2, int row) {
    bool result = true;

    int left = c1;
    int right = c2;

    while(1) {
        if (map[row][left] != map[row][right]) {
            return false;
        }

        if (left >= right) {
            break;
        }

        ++left;
        --right;
    }

    return result;
}

bool isPalinVert(int r1, int r2, int col) {
    bool result = true;

    int left = r1;
    int right = r2;

    while(1) {
        if (map[left][col] != map[right][col]) {
            return false;
        }

        if (left >= right) {
            break;
        }

        ++left;
        --right;
    }

    return result;
}

int main() {

    for (int t=1; t<=T; ++t) {
        int n;
        scanf("%d", &n);
        getchar();

        map.assign(len, vector<char> (len, 'A'));

        for (int r=0; r<len; ++r) {
            for (int c=0; c<len; ++c) {
                scanf("%1c", &map[r][c]);
            }
            getchar();
        }

        int count = 0;

        for (int r=0; r<len; ++r) {
            for (int c=0; c<=(len-n); ++c) {
                if (isPalinHori(c, c+n-1, r)) {
                    ++count;
                }
            }
        }

        for (int c=0; c<len; ++c) {
            for (int r=0; r<=(len-n); ++r) {
                if (isPalinVert(r, r+n-1, c)) {
                    ++count;
                }
            }
        }

        printf("#%d %d\n", t, count);

        map.clear();
    }

    return 0;
}