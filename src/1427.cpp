#include <iostream>

using namespace std;

string input;

void insert(int prev, int next) {
    char temp = input[prev];

    for (int i=prev; i<next; ++i) {
        input[i] = input[i+1];
    }

    input[next] = temp;
}

void QuickSort(int start, int len, int pivot) {
    if (len <= 1) {
        return;
    }

    int i = start;
    int j = start + len -1;

    while(1) {

        if (i == j) {
            if (input[i] < input[pivot]) {
                insert(pivot, i-1);
                pivot = i-1;
            } else {
                insert(pivot, i);
                pivot = i;
            }
            break;
        }

        if (input[i] >= input[pivot] || i == pivot) {
            ++i;
        } else {
            if (input[j] < input[pivot] || j == pivot) {
                --j;
            } else {
                char temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
        }
    }

    QuickSort(start, pivot-start, start);
    QuickSort(pivot+1, start+len-pivot-1, pivot+1);

}

int main() {

    getline(cin, input);

    QuickSort(0, input.size(), 0);

    printf("%d\n", atoi(input.c_str()));

    return 0;
}