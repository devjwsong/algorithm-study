#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> mnts;

int main() {

    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);

        mnts.push_back({x, y});
    }

    sort(mnts.begin(), mnts.end());

    vector<bool> visible (N, true);
    int count = N;

    for (int i=0; i<N; ++i) {
        if (visible[i]) {
            for (int j=i+1; j<N; ++j) {
                if ((mnts[j].first-mnts[j].second) <= (mnts[i].first-mnts[i].second) 
                        && (mnts[j].first+mnts[j].second) >= (mnts[i].first+mnts[i].second)) {
                    --count;
                    visible[i] = false;
                    break;
                } else if ((mnts[i].first-mnts[i].second) <= (mnts[j].first-mnts[j].second) 
                        && (mnts[i].first+mnts[i].second) >= (mnts[j].first+mnts[j].second)) {
                    if (visible[j]) {
                        --count;
                        visible[j] = false;
                    }
                }   
            }
        }
    }

    printf("%d\n", count);

    return 0;
}