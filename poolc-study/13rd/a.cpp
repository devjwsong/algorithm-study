#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> stats;

int memo[1001][16][16];

int main() {
    stats.push_back({-1, -1});

    int w, b;
    while(cin >> w >> b) {
        ++N;

        stats.push_back({w, b});
    }

    for (int i=0; i<N; ++i) {
        for (int w=0; w<=15; ++w) {
            for (int b=0; b<=15; ++b) {
                memo[i+1][w][b] = max(memo[i+1][w][b], memo[i][w][b]);

                if (w+1 <= 15) {
                    memo[i+1][w+1][b] = max(memo[i+1][w+1][b], memo[i][w][b] + stats[i+1].first);
                }

                if (b+1 <= 15) {
                    memo[i+1][w][b+1] = max(memo[i+1][w][b+1], memo[i][w][b] + stats[i+1].second);
                }
            }
        }
    }

    int answer = 0;

    for (int i=1; i<=N; ++i) {
        answer = max(answer, memo[i][15][15]);
    }

    cout<<answer<<"\n";

    return 0;
}