#include <iostream>

using namespace std;

int main() {

    while(1) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (a==0 && b==0 && c==0) {
            break;
        }

        int longest = max(a, max(b, c));
        int s1, s2;
        
        if (c == longest) {
            s1 = a;
            s2 = b;
        } else if (b == longest) {
            s1 = c;
            s2 = a;
        } else if (a == longest) {
            s1 = b;
            s2 = c;
        }

        if (longest*longest == s1*s1 + s2*s2) {
            printf("right\n");
        } else {
            printf("wrong\n");
        }
    }

    return 0;
}