#include <iostream>

using namespace std;

int arr[1000];

void SelectionSort(int N) {
    for (int i=0; i<N-1; ++i) {
        int min_value = arr[i];
        int min_index = i;
        for (int j=i+1; j<N; ++j) {
            if (min_value > arr[j]) {
                min_value = arr[j];
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main() {

    int N;
    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        scanf("%d", &arr[i]);
    }

    SelectionSort(N);

    for (int i=0; i<N; ++i) {
        printf("%d\n", arr[i]);
    }

    return 0;
}