#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int TC;
int N, M;
vector<int> weights;

int binary_search(int start, int left, int right, int value) {
    if (left+1 == right) {
        if (weights[left] > value || left==start) {
            return -1;
        } else {
            return weights[left];
        }
    }

    int mid = (left + right) / 2;
    if (weights[mid] <= value) {
        return binary_search(start, mid, right, value);
    } else {
        return binary_search(start, left, mid, value);
    }
}

int main() {

    scanf("%d", &TC);

    for (int t=1; t<=TC; ++t) {
        scanf("%d %d", &N, &M);

        weights.assign(N, 0);
        for (int i=0; i<N; ++i) {
            scanf("%d", &weights[i]);
        }

        sort(weights.begin(), weights.end());

        int answer = 0;
        for (int i=0; i<N; ++i) {
            int sum = weights[i];
            int result = binary_search(i, i, N, M-sum);

            if (result != -1) {
                sum += result;
                answer = max(answer, sum);
            }
        }

        if (answer == 0) {
            printf("#%d %d\n", t, -1);
        } else {
            printf("#%d %d\n", t, answer);
        }
    }

    return 0;
}