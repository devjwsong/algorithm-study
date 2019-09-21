#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> people;

int memo[101][11];

int main() {

    scanf("%d %d", &N, &M);
    people.assign(N+1, 0);

    for (int i=1; i<=N; ++i) {
        scanf("%d", &people[i]);
    }

    

    return 0;
}