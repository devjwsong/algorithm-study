#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        int N;
        scanf("%d", &N);

        vector<int> logs;

        for (int i=0; i<N; ++i) {
            int input;
            scanf("%d", &input);
            logs.push_back(input);
        }

        sort(logs.begin(), logs.end());

        vector<int> incs;
        vector<int> decs;

        for (int i=0; i<N; ++i) {
            if (i % 2 == 0) {
                incs.push_back(logs[i]);
            } else {
                decs.push_back(logs[i]);
            }
        }

        sort(decs.begin(), decs.end(), greater<int>());

        for (int i=0; i<N; ++i) {
            if (i < incs.size()) {
                logs[i] = incs[i];
            } else {
                logs[i] = decs[i-incs.size()];
            }
        } 

        int answer = 0;

        for (int i=0; i<N; ++i) {
            if (i == N-1) {
                if (abs(logs[i] - logs[0]) >= answer) {
                    answer = abs(logs[i] - logs[0]);
                }
            } else {
                if (abs(logs[i] - logs[i+1]) >= answer) {
                    answer = abs(logs[i] - logs[i+1]);
                }
            }
        }

        printf("%d\n", answer);

    }

    return 0;
}