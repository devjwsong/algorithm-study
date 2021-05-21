#include <iostream>

using namespace std;

int main() {

    int check[26];

    for (int i=0; i<26; ++i) {
        check[i] = -1;
    }

    string str;
    getline(cin, str);

    for (int i=0; i<str.size(); ++i) {
        if (check[str[i]-'a'] == -1) {
            check[str[i]-'a'] = i;
        }
    }

    for (int i=0; i<26; ++i) {
        printf("%d ", check[i]);
    }
    printf("\n");

    return 0;
}