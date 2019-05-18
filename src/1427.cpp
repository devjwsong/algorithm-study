#include <iostream>
#include <algorithm>

using namespace std;

string input;

void QuickSort(int start, int len, int pivot) {
    if (len <= 1) {
        return;
    }

    int i = start;
    int j = start + len -1;

    while(1) {

        if (i == j) {
            if ((input[i] >= input[pivot] && i > pivot) || (input[i] < input[pivot] && i < pivot)) {
                swap(input[i], input[pivot]);
            }
            break;
        }

        if (input[i] >= input[pivot] || i == pivot) {
            ++i;
        } else {
            if (input[j] < input[pivot] || j == pivot) {
                --j;
            } else {
                int temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }

    pivot = i;
    QuickSort(start, pivot-start, start + (pivot-start)/2);
    QuickSort(pivot+1, start+len-pivot-1, pivot+1 + (start+len-pivot-1)/2);

}

int main() {

    getline(cin, input);

    QuickSort(0, input.size(), input.size()/2);

    printf("%d\n", atoi(input.c_str()));

    return 0;
}