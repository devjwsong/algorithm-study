#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<pair<int, int>> plan;

int memo[17];

int main() {

    scanf("%d", &N);

    plan.assign(N+1, {0, 0});

    for (int i=1; i<=N; ++i) {
        int t, p;
        scanf("%d %d", &t, &p);

        plan[i] = {t, p};
    }

    for (int i=1; i<=N; ++i) {
        
        memo[i] = max(memo[i], memo[i-1]);

        if (i+plan[i].first-1<=N) {
            memo[i+plan[i].first-1] = max(memo[i+plan[i].first-1], memo[i-1]+plan[i].second);
        }
    }

    int answer = 0;

    for (int i=1; i<=N; ++i) {
        answer = max(answer, memo[i]);
    }

    printf("%d\n", answer);

    return 0;
}