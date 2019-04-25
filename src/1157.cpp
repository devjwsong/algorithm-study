#include <iostream>

using namespace std;

int main() {

    int check[26] = {0, };

    string str;
    getline(cin, str);

    for (int i=0; i<str.size(); ++i) {
        if (str[i] >= 65 && str[i] <= 90) {
            check[str[i]-'A'] += 1;
        } else if (str[i] >= 97 && str[i] <= 122) {
            check[str[i]-'a'] += 1;
        }
    }

    int max_count = 0;
    int max_letter = 0;
    bool duplicated  = false;

    for (int i=0; i<26; ++i) {
        if (max_count < check[i]) {
            max_count = check[i];
            max_letter = i;
            duplicated = false;
        } else if (max_count == check[i]) {
            duplicated = true;
        }
    }

    if (duplicated) {
        printf("?\n");
    } else {
        printf("%c\n", max_letter + 'A');
    }

    return 0;
}