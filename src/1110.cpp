#include <iostream>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    int cal = n;
    int count = 0;

    while(1) {

        int ten = cal / 10;
        int one = cal % 10;

        cal = one * 10 + (ten+one) % 10;
        
        ++count;

        if (cal == n) {
            break;
        }

    }

    printf("%d\n", count);

    return 0;
}