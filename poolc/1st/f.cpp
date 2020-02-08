#include <iostream>
#include <vector>

using namespace std;

int N;

int pSum[3][100001]; // 0: H, 1: S, 2: P

int charToInt(char c) {
    if (c == 'H') {
        return 0;
    } else if (c == 'S') {
        return 1;
    } else if (c == 'P') {
        return 2;
    }
}

int main() {

    cin>>N;

    for (int i=1; i<=N; ++i) {
        char c;
        cin>>c;
        ++pSum[charToInt(c)][i];
    }

    for (int i=2; i<=N; ++i) {
        pSum[0][i] += pSum[0][i-1];
        pSum[1][i] += pSum[1][i-1];
        pSum[2][i] += pSum[2][i-1];
    }

    int count = 0;

    for (int i=1; i<=N; ++i) {
        int result = 0;

        int left = 0;
        int right = 0;
        for (int f=0; f<3; ++f) {
            for (int s=0; s<3; ++s) {
                left = pSum[f][i-1];
                right = pSum[s][N] - pSum[s][i-1];
                
                if (left+right >= result) {
                    result = left + right;
                }
            }
        }

        if (result >= count) {
            count = result;
        }
    }

    printf("%d\n", count);

    return 0;
}