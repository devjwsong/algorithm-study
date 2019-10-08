#include <iostream>

using namespace std;

int N;
long long heap[262144];
int count;

void sortUpToDown(int idx) {
    if (heap[idx*2] == 0 && heap[idx*2+1] == 0) {
        return;
    } else {
        if (heap[idx] >= max(heap[idx*2], heap[idx*2+1])) {
            return;
        } else {
            if (heap[idx*2] > heap[idx*2+1]) {
                swap(heap[idx], heap[idx*2]);
                sortUpToDown(idx*2);
            } else {
                swap(heap[idx], heap[idx*2+1]);
                sortUpToDown(idx*2+1);
            }
        }
    }
}

void sortDownToUp(int idx) {
    if (idx == 1) {
        return;
    } else {
        if (heap[idx] > heap[idx/2]) {
            swap(heap[idx], heap[idx/2]);
            sortDownToUp(idx/2);
        }
    }
}

int main() {

    scanf("%d", &N);

    for (int i=1; i<=N; ++i) {
        int x;
        scanf("%d", &x);

        if (x == 0) {
            printf("%lld\n", heap[1]);
            if (count > 0) {
                heap[1] = heap[count];
                heap[count] = 0;
                --count;
                sortUpToDown(1);
            }
        } else {
            ++count;
            heap[count] = x;
            sortDownToUp(count);
        }
    }

    return 0;
}