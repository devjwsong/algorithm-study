#include <iostream>

using namespace std;

int main() {

    int T;
    scanf("%d", &T);
    getchar();

    for (int test=0; test<T; ++test) {
        string input;
        getline(cin, input);

        int score = 0;
        int add = 1;

        for (int i=0; i<input.size(); ++i) {
            if (input[i] == 'O') {
                score += add;
                ++add;
            } else {
                add = 1;
            }
        }

        printf("%d\n", score);
    }

    return 0;
}