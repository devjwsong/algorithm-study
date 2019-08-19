#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N, M, C;
vector<int> cows; 

bool isPossible(int x) {
    int count = 0;
    int start = cows[0];
    int cur = 1;

    for (int i=1; i<N; ++i) {
        if (cur < C && cows[i] - start <= x) {
            ++cur;
        } else {
            ++count;
            cur = 1;
            start = cows[i];
        }

        if (i == N-1) {
            ++count;
        }
    }

    return count <= M;
}

int main() {

    scanf("%d %d %d", &N, &M, &C);

    for (int i=0; i<N; ++i) {
        int p;
        scanf("%d", &p);
        cows.push_back(p);
    }

    sort(cows.begin(), cows.end());

    int low = 0;
    int high = 1e+9;

    while(1) {
        if (low > high) {
            break;
        }

        int mid = (low + high) / 2;

        if (isPossible(mid)) {
            high = mid-1;
        } else {
            low = mid+1;
        }

    }

    printf("%d\n", low);

    return 0;
}