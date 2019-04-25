#include <iostream>

using namespace std;

int main() {

    int n;
    scanf("%d", &n);

    int group = 1;
    if (n != 1) {
        int k = 0;
        int num = 1;
        while(1) {
            if (n >= (1+6*k+1) && n <= (1+6*(k+num-1)+6)) {
                group = num + 1;
                break;
            }
            k += num;
            ++num;
        }
    }

    printf("%d\n", group);

    return 0;
}