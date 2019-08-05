#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> seq;
long long count = 0;

void mergeSort(int start, int end) {

    if (start == end) {
        return;
    } else {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid+1, end);

        int i = start;
        int j = mid+1;

        vector<int> temp;

        while(1) {
            if (i > mid && j > end) {
                break;
            } else if (i <= mid && j > end) {
                temp.push_back(seq[i]);
                ++i;
            } else if (i > mid && j <= end) {
                temp.push_back(seq[j]);
                ++j;
            } else if (i <= mid && j <= end) {
                if (seq[i] > seq[j]) {
                    count += (mid+1-i);
                    temp.push_back(seq[j]);
                    ++j;
                } else {
                    temp.push_back(seq[i]);
                    ++i;
                }
            }
        }

        for (int k=start; k<=end; ++k) {
            seq[k] = temp[k-start];
        }
    }
    
}

int main() {

    scanf("%d", &N);
    seq.assign(N, 0);

    for (int i=0; i<N; ++i) {
        scanf("%d", &seq[i]);
    }

    mergeSort(0, N-1);
    
    printf("%lld\n", count);

    return 0;
}