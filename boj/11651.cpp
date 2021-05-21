#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> v;

bool isSmaller(pair<int, int> a, pair<int, int> b) {
    if (a.second < b.second) {
        return true;
    } else if (a.second > b.second) {
        return false;
    } else {
        return a.first < b.first;
    }
}

int main() {

    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v.push_back({a,b});
    }

    sort(v.begin(), v.end(), isSmaller);

    for (int i=0; i<v.size(); ++i) {
        printf("%d %d\n", v[i].first, v[i].second);
    }

    return 0;
}