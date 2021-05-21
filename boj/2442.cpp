#include <iostream>

using namespace std;

int N;

int main() {

    scanf("%d", &N);

    int num_col = 2*N-1;
    for (int r=1; r<=N; ++r) {
        int star = 2*r-1;
        int pad = (num_col - star) / 2;
        
        for (int i=1; i<=pad; ++i) {
            printf(" ");
        }

        for (int i=1; i<=star; ++i) {
            printf("*");
        }

        printf(" ");

        printf("\n");
    }

    return 0;
}