#include <iostream>
#include <vector>

using namespace std;

int T;
int H, W;

vector<vector<char>> grill;

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        scanf("%d %d", &H, &W);
        getchar();

        grill.assign(H, vector<char> (W, '.'));
        for (int r=0; r<H; ++r) {
            for (int c=0; c<W; ++c) {
                scanf("%c", &grill[r][c]);
            }
            getchar();
        }

        for (int r=0; r<H; ++r) {
            for (int c=W-1; c>=0; --c) {
                printf("%c", grill[r][c]);
            }
            printf("\n");
        }

        grill.clear();
    }

    return 0;
}