#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> people;

int main() {

    scanf("%d", &N);
    people.assign(N+1, 0);

    for (int i=1; i<=N; ++i) {
        scanf("%d", &people[i]);
    }

    sort(people.begin(), people.end());

    int sum = 0;
    int answer = 0;

    for (int i=1; i<=N; ++i) {
        sum += people[i];
        answer += sum;
    }

    printf("%d\n", answer);

    return 0;
}