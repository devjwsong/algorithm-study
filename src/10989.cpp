#include <iostream>

using namespace std;

int count[10001];

void countingSort(int N) {

    for (int i=1; i<10001; ++i) {
        for (int j=0; j<count[i]; ++j) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; ++i) {
        int input;
        scanf("%d", &input);
        ++count[input];
    }

    countingSort(N);

    return 0;
}