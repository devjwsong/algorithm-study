#include <iostream>

using namespace std;

int main() {

    int N;
    scanf("%d", &N);
    getchar();

    string words[N];

    for (int i=0; i<N; ++i) {
        getline(cin, words[i]);
    }

    int check[N][26]  = {{0, }, };
    int count = 0;

    for (int i=0; i<N; ++i) {
        bool is_group = true;
        for (int j=0; j<words[i].size(); ++j) {
            if (check[i][words[i][j]-'a'] == 0) {
                check[i][words[i][j]-'a'] += 1;
            } else if (check[i][words[i][j]-'a'] > 0) {
                if (words[i][j-1] != words[i][j]) {
                    is_group = false;
                    break;
                }
            }
        }

        if (is_group) ++count;
    }

    printf("%d\n", count);

    return 0;
}