#include <iostream>

using namespace std;

int arr[1000];

void BubbleSort(int N) {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {

    int N;
    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        scanf("%d", &arr[i]);
    }

    BubbleSort(N);

    for (int i=0; i<N; ++i) {
        printf("%d\n", arr[i]);
    }

    return 0;
}