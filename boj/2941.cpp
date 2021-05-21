#include <iostream>

using namespace std;

int main() {

    string str;
    getline(cin, str);

    int count = 0;
    for (int i=0; i<str.size(); ++i) {
        if (i != 0) {
            if (str[i] == '=') {
                if (str[i-1] == 'c' || str[i-1] == 's' || str[i-1] == 'z') {
                    continue;
                } else {
                    ++count;
                }
            } else if (str[i] == '-') {
                if (str[i-1] == 'c' || str[i-1] == 'd') {
                    continue;
                } else {
                    ++count;
                }
            } else if (str[i] == 'j') {
                if (str[i-1] == 'l' || str[i-1] == 'n') {
                    continue;
                } else {
                    ++count;
                }
            } else if (str[i] == 'z') {
                if (str[i-1] == 'd') {
                    if (i == str.size()-1 || str[i+1] != '=') {
                        ++count;
                    } else {
                        continue;
                    }
                } else {
                    ++count;
                }
            } else {
                ++count;
            }
        } else {
            ++count;
        }
    }

    printf("%d\n", count);

    return 0;
}