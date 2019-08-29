#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int N;
int W;

vector<pair<int, int>> cases;
int memo[1001][1001];
pair<int, int> track[1001][1001];

int sum = INT_MAX;
vector<int> answers;

int final_1 = 0;
int final_2 = 0;

int dist(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}

void memoization() {
    memo[1][0] = dist({1, 1}, cases[1]);
    memo[0][1] = dist({N, N}, cases[1]);
    track[1][0] = {0, 0};
    track[0][1] = {0, 0};

    for (int i=2; i<=W; ++i) {
        for (int j=0; j<i-1; ++j) {
            memo[i][j] = memo[i-1][j] + dist(cases[i], cases[i-1]);
            track[i][j] = {i-1, j};
        }

        memo[i][i-1] = INT_MAX;
        for (int j=0; j<i-1; ++j) {
            if (j == 0) {
                if (memo[i][i-1] > memo[j][i-1] + dist({1, 1}, cases[i])) {
                    memo[i][i-1] = memo[j][i-1] + dist({1, 1}, cases[i]);
                    track[i][i-1] = {j, i-1};
                }
            } else {
                if (memo[i][i-1] > memo[j][i-1] + dist(cases[j], cases[i])) {
                    memo[i][i-1] = memo[j][i-1] + dist(cases[j], cases[i]);
                    track[i][i-1] = {j, i-1};
                }
            }
        }

        for (int j=0; j<i-1; ++j) {
            memo[j][i] = memo[j][i-1] + dist(cases[i], cases[i-1]);
            track[j][i] = {j, i-1};
        }

        memo[i-1][i] = INT_MAX;
        for (int j=0; j<i-1; ++j) {
            if (j == 0) {
                if (memo[i-1][i] > memo[i-1][j] + dist({N, N}, cases[i])) {
                    memo[i-1][i] = memo[i-1][j] + dist({N, N}, cases[i]);
                    track[i-1][i] = {i-1, j};
                }
            } else {
                if (memo[i-1][i] > memo[i-1][j] + dist(cases[j], cases[i])) {
                    memo[i-1][i] = memo[i-1][j] + dist(cases[j], cases[i]);
                    track[i-1][i] = {i-1, j};
                }
            }
        }
    }
}

void trace() {
   int cur1 = final_1;
   int cur2 = final_2;

   while(1) {
       if (cur1 == 0 && cur2 == 0) {
           break;
       }

       pair<int, int> prev = track[cur1][cur2];
       int prev1 = prev.first;
       int prev2 = prev.second;

       if (cur1 != prev1 && cur2 == prev2) {
           answers.push_back(1);
       } else if (cur1 == prev1 && cur2 != prev2) {
           answers.push_back(2);
       }

       cur1 = prev1;
       cur2 = prev2;
   } 
}

int main() {

    scanf("%d", &N);
    scanf("%d", &W);

    cases.assign(W+1, {0, 0});

    for (int i=1; i<=W; ++i) {
        scanf("%d %d", &cases[i].first, &cases[i].second);
    }

    memoization();

    for (int i=0; i<W; ++i) {
        int value = min(memo[W][i], memo[i][W]);

        if (value <= sum) {
            sum = value;

            if (memo[W][i] <= memo[i][W]) {
                final_1 = W;
                final_2 = i;
            } else {
                final_1 = i;
                final_2 = W;
            }
        }
    }

    trace();

    printf("%d\n", sum);
    for (int i=answers.size()-1; i>=0; --i) {
        printf("%d\n", answers[i]);
    }    

    return 0;
}