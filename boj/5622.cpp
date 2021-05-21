#include <iostream>

using namespace std;

int getTime(char c) {

    int num = 0;

    if (c>=65 && c<=67) {
        num = 2;
    } else if (c>=68 && c<=70) {
        num = 3;
    } else if (c>=71 && c<=73) {
        num = 4;
    } else if (c>=74 && c<=76) {
        num = 5;
    } else if (c>=77 && c<=79) {
        num = 6;
    } else if (c>=80 && c<=83) {
        num = 7;
    } else if (c>=84 && c<=86) {
        num = 8;
    } else if (c>=87 && c<=90) {
        num = 9;
    }

    return (num-1) + 2;
}

int main() {

    string str;
    getline(cin, str);

    int result = 0;

    for (int i=0; i<str.size(); ++i) {
        result += getTime(str[i]);
    }

    printf("%d\n", result);

    return 0;
}