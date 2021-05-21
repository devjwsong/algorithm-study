#include <iostream>

using namespace std;

int arr[1000001];

void sortSubtree(int index, int N) {

    if (index*2 > N && index*2+1 > N) {
        return;
    } else if (index*2 <= N && index*2+1 > N) {
        if (arr[index] < arr[index*2]) {
            swap(arr[index], arr[index*2]);
            sortSubtree(index*2, N);
        }
    } else {
        if (arr[index] < arr[index*2] || arr[index] < arr[index*2+1]) {
            if (arr[index*2] >= arr[index*2+1]) {
                swap(arr[index], arr[index*2]);
                sortSubtree(index*2, N);
            } else {
                swap(arr[index], arr[index*2+1]);
                sortSubtree(index*2+1, N);
            }
        }
    }
    
}

void makeHeap(int N) {
    for (int i=N; i>=1; --i) {
        sortSubtree(i, N);
    }
}

void heapSort(int length) {

    if (length == 1) {
        return;
    }

    swap(arr[1], arr[length]);
    sortSubtree(1, length-1);
    heapSort(length-1);
}

int main() {

    int N;
    scanf("%d", &N);

    for (int i=1; i<=N; ++i) {
        scanf("%d", &arr[i]);
    }

    makeHeap(N);
    heapSort(N);

    for (int i=1; i<=N; ++i) {
        printf("%d\n", arr[i]);
    }

    return 0;
}