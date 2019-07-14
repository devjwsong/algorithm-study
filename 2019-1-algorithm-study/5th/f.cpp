#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> hs;

vector<int> up;
vector<int> down;

int main() {

    scanf("%d %d", &N, &M);

    hs.assign(N+1, 0);
    for (int i=1; i<=N; ++i) {
        scanf("%d", &hs[i]);
    }

    up = hs;
    down = hs;

    int upNum = 1;
    for (int i=1; i<=N; ++i) {
        up[i] = upNum;
        
        if (hs[i+1] <= hs[i]) {
            ++upNum;
        }
    }

    int downNum = 1;
    for (int i=1; i<=N; ++i) {
        down[i] = downNum;
        
        if (hs[i+1] >= hs[i]) {
            ++downNum;
        }
    }

    int count = up[up.size()-1];

    for (int i=1; i<=M; ++i) {
        int l, r;
        scanf("%d %d", &l, &r);

        int newCount = count;
        int upCount = up[r] - up[l] + 1;
        int downCount = down[r] - down[l] + 1;

        if (l != 1 && up[l] == up[l-1]) {
            ++newCount;
        }

        if (r != N && up[r] == up[r+1]) {
            ++newCount;
        }

        newCount = newCount - upCount + downCount;

        if (l != 1 && hs[r] > hs[l-1]) {
            --newCount;
        }

        if (r != N && hs[l] < hs[r+1]) {
            --newCount;
        }

        printf("%d\n", newCount);
    }

    return 0;
}