#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> seq;

int main() {

    scanf("%d", &N);
    seq.assign(N, 0);

    for (int i=0; i<N; ++i) {
        int input;
        scanf("%d", &input);
        seq[i] = input;
    }

    int index = -1;

    for (int i=N-2; i>=0; --i) {
        if (seq[i+1] > seq[i]) {
            continue;
        } else {
            index = i;
            break;
        }
    }

    printf("%d\n", index+1);

    return 0;
}