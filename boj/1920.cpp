#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int M;
vector<int> seq;

int binarySearch(int input) {
    int l = 0;
    int r = N;

    while(1) {
        int m = (l + r) / 2;
        int prev_l = l;
        int prev_r = r;
        if (seq[m] == input) {
            return 1;
        } else if (seq[m] < input) {
            l = m;
        } else if (seq[m] > input) {
            r = m;
        }

        if (prev_l == l && prev_r == r) {
            break;
        }
    }

    return 0;
}

int main() {

    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        int p;
        scanf("%d", &p);
        seq.push_back(p);
    }

    sort(seq.begin(), seq.end());

    scanf("%d", &M);

    for (int j=0; j<M; ++j) {
        int input;
        scanf("%d", &input);
        printf("%d\n", binarySearch(input));
    }

    return 0;
}