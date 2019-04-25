#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);

    for (int test=0; test<T; ++test) {

        int r;
        scanf("%d ", &r);

        string str;
        getline(cin, str);

        for (int i=0; i<str.size(); ++i) {
            for (int j=0; j<r; ++j) {
                printf("%c", str[i]);
            }
        }

        printf("\n");

    }

    return 0;
}