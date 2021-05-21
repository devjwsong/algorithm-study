#include <iostream>

using namespace std;

int arr[1000];

void InsertionSort(int N) {
    for (int i=1; i<N; ++i) {
        int index = 0;
        for (int j=i-1; j>=0; --j) {
            if (arr[i] >= arr[j]) {
                index = j+1;
                break;
            }
        }

        if (index == i) {
            continue;
        }

        int value = arr[i];
        for (int j=i; j>index; --j) {
            arr[j] = arr[j-1];
        }
        arr[index] = value;

    }
}

int main() {

    int N;
    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        scanf("%d", &arr[i]);
    }

    InsertionSort(N);

    for (int i=0; i<N; ++i) {
        printf("%d\n", arr[i]);
    }

    return 0;
}