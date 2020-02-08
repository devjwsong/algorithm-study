#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int N;

vector<int> A;

int main() {

    scanf("%d", &T);

    for (int t=1; t<=T; ++t) {
        scanf("%d", &N);

        int answer = 0;

        A.assign(N, 0);
        for (int i=0; i<N; ++i) {
            scanf("%d", &A[i]);
        }

        sort(A.begin(), A.end());

        for (int i=0; i<N; ++i) {
            if (i == 0) {
                answer += (2*A[i]+1);
            } else {
                if (A[i] >= A[i-1]) {
                    answer += (1+2*A[i]-A[i-1]);
                } else {
                    answer += (1+A[i]);
                }
            }
        }

        printf("#%d %d\n",t , answer);
    }

    return 0;
}