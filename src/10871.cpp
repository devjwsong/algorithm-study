#include <iostream>

using namespace std;

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    
    for (int i=0; i<n; ++i) {
        int value;
        scanf("%d ", &value);
        if (value < x) {
            printf("%d ", value);
        }
    }
    
    printf("\n");
    
    return 0;
}