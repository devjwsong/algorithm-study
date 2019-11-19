#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, T;
vector<int> seq;
vector<int> cpy;

bool isPossible(int d) {
    cpy = seq;
    int count = 0;

    for (int i=0; i<N-1; ++i) {
        if (cpy[i+1]>cpy[i]+d) {
            int value = cpy[i+1]-cpy[i]-d;
            count += value;
            cpy[i+1] -= value;
        }
    }

    for (int i=N-1; i>=1; --i) {
        if (cpy[i-1]>cpy[i]+d) {
            int value = cpy[i-1]-cpy[i]-d;
            count += value;
            cpy[i-1] -= value;
        }
    }

    if (count <= T) {
        T -= count;
        return true;
    } else {
        return false;
    }
}

int main() {

    scanf("%d %d", &N, &T);
    seq.assign(N, 0);

    for (int i=0; i<N; ++i) {
        scanf("%d", &seq[i]);
    }
    
    int l = -1;
    int r = 1000000001;
    while(1) {
        if (l+1==r) {
            break;
        }

        int m = (l+r)/2;

        if (isPossible(m)) {
            seq = cpy;
            r = m;
        } else {
            l = m;
        }
    }

    for (int i=0; i<N; ++i) {
        printf("%d ", seq[i]);
    }
    printf("\n");

    return 0;
}