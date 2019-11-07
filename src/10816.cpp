#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N;
unordered_map<int, int> cards;
int M;

int main() {

    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        int p;
        scanf("%d", &p);

        ++cards[p];
    }

    scanf("%d", &M);

    for (int i=0; i<M; ++i) {
        int target;
        scanf("%d", &target);

        if (cards.find(target) != cards.end()) {
            printf("%d ", cards[target]);
        } else {
            printf("0 ");
        }
    }
    printf("\n");

    return 0;
}