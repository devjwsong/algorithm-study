#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> cards;
vector<int> seq;

int main() {

    scanf("%d %d", &N, &M);

    for (int i=0; i<N; ++i) {
        int p;
        scanf("%d", &p);
        cards.push_back(p);
    }

    seq.assign(N, 0);
    for (int i=seq.size()-1; i>=seq.size()-3; --i) {
        seq[i] = 1;
    }

    int answer = 0;

    do {
        int value = 0;
        for (int i=0; i<seq.size(); ++i) {
            if (seq[i] == 1) {
                value += cards[i];
            }
        }
        if (value <= M) {
            answer = max(answer, value);
        }
    } while(next_permutation(seq.begin(), seq.end()));

    printf("%d\n", answer);

    return 0;
}