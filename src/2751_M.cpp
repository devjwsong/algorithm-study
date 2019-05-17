#include <iostream>

using namespace std;

int arr[1000000];

int* resample(int *arr1, int len1, int *arr2, int len2) {

    int *resampled = new int[len1+len2];

    int resampled_index = 0;
    int arr1_index = 0;
    int arr2_index = 0;

    while(1) {
        if (arr1_index == len1 && arr2_index == len2) {
            break;
        } else if (arr2_index == len2) {
            resampled[resampled_index] = arr1[arr1_index];
            ++arr1_index;
        } else if (arr1_index == len1) {
            resampled[resampled_index] = arr2[arr2_index];
            ++arr2_index;
        } else {
            if (arr1[arr1_index] <= arr2[arr2_index]) {
                resampled[resampled_index] = arr1[arr1_index];
                ++arr1_index;
            } else {
                resampled[resampled_index] = arr2[arr2_index];
                ++arr2_index;
            }   
        }

        ++resampled_index;
    }

    return resampled;
}

int* MergeSort(int start, int len) {
    
    if (len == 1) {
        int *element = new int[len]{arr[start]};
        return element;
    }

    int half = len/2;
    int *resampled = resample(MergeSort(start, half), half, MergeSort(start+half, len-half), len-half);

    return resampled;

}

int main() {

    int N;
    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        scanf("%d", &arr[i]);
    }

    int* result = MergeSort(0, N);

    for (int i=0; i<N; ++i) {
        printf("%d\n", result[i]);
    }

    return 0;
}