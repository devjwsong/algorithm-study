#include <iostream>

using namespace std;

int arr[1000];

void insertNum(int prev, int next) {
    int value = arr[prev];

    for(int i=prev; i<next; ++i) {
        arr[i] = arr[i+1];
    }

    arr[next] = value;
}

void QuickSort(int start, int len, int pivot) {
    if (len <= 1) {
        return;
    }

    int i = start;
    int j = start + len -1;

    while(1) {
        if (i == j) {
            if (arr[pivot] <= arr[i]) {
                insertNum(pivot, i-1);
                --i;
                --j;
            } else {
                if (i+1 >= len) {
                    insertNum(pivot, i);
                } else {
                    insertNum(pivot, i+1);
                    ++i;
                    ++j;
                }
            }
            break;
        }

        if (arr[i] <= arr[pivot] || i == pivot) {
            ++i;
        } else {
            if (arr[j] >= arr[pivot] || j == pivot) {
                --j;
            } else {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    pivot = i;
    QuickSort(start, pivot-start, start);
    QuickSort(pivot+1, start+len-pivot-1, pivot+1);

}

int main() {

    int N;
    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        scanf("%d", &arr[i]);
    }

    QuickSort(0, N, 0);

    for (int i=0; i<N; ++i) {
        printf("%d\n", arr[i]);
    }

    return 0;
}