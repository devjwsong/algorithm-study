#include <iostream>

using namespace std;

int M;
int S;

void add(int x) {
    S = S | (1 << x);
}

void remove(int x) {
    S = S & ~(1 << x);
}

bool check(int x) {
    if (S & (1 << x)) {
        return true;
    } else {
        return false;
    }
}

int main() {

    scanf("%d", &M);
    getchar();

    S = 0;

    for (int t=1; t<=M; ++t) {
        char command[11];
        int value;
        scanf(" %s", &command);
        scanf(" %d", &value);

        if (command[0] == 'e') {
            S = 0;
        } else if (command[0] == 'a' && command[1] == 'l') {
            S = (1<<21) - 1;
        } else if (command[0] == 'a' && command[1] == 'd') {
            add(value);
        } else if (command[0] == 'r') {
            remove(value);
        } else if (command[0] == 'c') {
            bool result = check(value);
            if (result) {
                printf("1\n");
            } else {
                printf("0\n");
            }
        } else if (command[0] == 't') {
            if (check(value)) {
                remove(value);
            } else {
                add(value);
            }
        }

        // cout<<"S is "<<S<<endl;
    }

    return 0;
}