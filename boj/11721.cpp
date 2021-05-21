#include <iostream>

using namespace std;

int main() {

    string str;
    getline(cin, str);

    int num = str.length() / 10;

    for (int i=0; i<num; ++i) {
        printf("%s\n", str.substr(0, 10).c_str());
        str = str.substr(10);
    }

    printf("%s\n", str.c_str());

    return 0;
}