#include <iostream>

using namespace std;

int main() {
    int num = 0;
    scanf("%d", &num);
    cin.get();

    int value = 0;

    for (int i=0; i<num; ++i) {
        char digit; 
        cin.get(digit);
        value += (digit - '0');
    }

    printf("%d\n", value);

    return 0;
}