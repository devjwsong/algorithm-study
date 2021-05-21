#include <iostream>

using namespace std;

int main() {

    int notes[8];

    for (int i=0; i<8; ++i) {
        scanf("%d", &notes[i]);
    }

    string status;

    if (notes[0] < notes[1]) {
        status = "ascending";
    } else {
        status = "descending";
    }

    for (int i=1; i<8; ++i) {
        if (notes[i-1] < notes[i]) {
            if (status == "ascending") {
                continue;
            } else {
                status = "mixed";
                break;
            }
        } else {
            if (status == "descending") {
                continue;
            } else {
                status = "mixed";
                break;
            }
        }
    }

    printf("%s\n", status.c_str());

    return 0;
}