#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> times;

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second) {
        return true;
    } else if (p1.second == p2.second) {
        return p1.first < p2.first;
    } else {
        return false;
    }
}

bool compatible(pair<int, int> p1, pair<int, int> p2) {
    return p1.second <= p2.first;
}

int main() {

    scanf("%d", &N);
    times.assign(N, {0,0});

    for (int i=0; i<N; ++i) {
        scanf("%d %d", &times[i].first, &times[i].second);
    }

    sort(times.begin(), times.end(), compare);

    int answer = 1;

    pair<int, int> cur = times[0];
    for (int i=1; i<N; ++i) {
        if (compatible(cur, times[i])) {
            ++answer;
            cur = times[i];
        }
    }

    printf("%d\n", answer);

    return 0;
}