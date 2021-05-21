#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[500000];

void printFreq(int N) {
    int prev = arr[0];
    int count = 1;
    int max_count = -1;
    vector<int> cand;

    for (int i=1; i<N; ++i) {
        if (prev == arr[i]) {
            ++count;
        } else {
            if (count == max_count) {
                cand.push_back(prev);
            } else if (count > max_count) {
                max_count = count;
                cand.clear();
                cand.push_back(prev);
            }

            prev = arr[i];
            count = 1;
        }

        if (i == N-1) {
            if (count == max_count) {
                cand.push_back(arr[i]);
            } else if (count > max_count) {
                cand.clear();
                cand.push_back(arr[i]);
            }
        }
    }

    if (N == 1) {
        cand.push_back(arr[0]);
    }

    if (cand.size() > 1) {
        printf("%d\n", cand[1]);
    } else {
        printf("%d\n", cand[0]);
    }
}

int main() {

    int N;
    scanf("%d", &N);

    int sum = 0;

    for (int i=0; i<N; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("%.0lf\n", (double) sum / (double) N);

    sort(arr, arr+N);

    printf("%d\n", arr[N/2]);

    printFreq(N);
    
    printf("%d\n", arr[N-1] - arr[0]);

    return 0;
}