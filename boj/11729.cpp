#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> moves;

void hanoi(int n, int from, int to, int by) {
    if (n == 1) {
        moves.push_back({from, to});
    } else {
        hanoi(n-1, from, by, to);
        hanoi(1, from, to, by);
        hanoi(n-1, by, to, from);
    }
}

int main() {

    scanf("%d", &N);

    hanoi(N, 1, 3, 2);

    printf("%lu\n", moves.size());

    for (int i=0; i<moves.size(); ++i) {
        printf("%d %d\n", moves[i].first, moves[i].second);
    }

    return 0;
}