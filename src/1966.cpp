#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for (int test=0; test<T; ++test) {
        int N, m;
        scanf("%d %d", &N, &m);

        queue<pair<int, int>> q;
        vector<int> scores;

        for (int i=0; i<N; ++i) {
            int input;
            scanf("%d", &input);

            q.push(pair<int, int>(i, input));
            scores.push_back(input);
        }

        sort(scores.begin(), scores.end(), greater<int>());

        int count = 0;

        while(1) {
            
            pair<int, int> front = q.front();

            if (front.second == scores[0]) {
                q.pop();
                ++count;
                scores.erase(scores.begin());

                if (front.first == m) {
                    break;
                }

            } else {
                q.pop();
                q.push(front);
            }

        }

        printf("%d\n", count);

    }

    return 0;
}