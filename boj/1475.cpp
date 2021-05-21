#include <iostream>

using namespace std;

int main() {

    string str;
    getline(cin, str);

    int set[str.size()][10] = {0, };

    int N = atoi(str.c_str());

    int num_set = 1;
    while(1) {
        int r = N % 10;

        bool okay = false;
        for (int s=0; s<num_set; ++s) {
            
            if (r == 9) {
                if (set[s][r] == 0) {
                    okay = true;
                    set[s][r] = 1;
                    break;
                } else if (set[s][r-3] == 0) {
                    okay = true;
                    set[s][r-3] = 1;
                    break;
                }
            } else if (r == 6) {
                if (set[s][r] == 0) {
                    okay = true;
                    set[s][r] = 1;
                    break;
                } else if (set[s][r+3] == 0) {
                    okay = true;
                    set[s][r+3] = 1;
                    break;
                }
            } else {
                if (set[s][r] == 0) {
                    okay = true;
                    set[s][r] = 1;
                    break;
                }
            }
        }

        if (!okay) {
            set[num_set][r] = 1;
            ++num_set;
        }

        N /= 10;

        if (N == 0) {
            break;
        }

    }

    printf("%d\n", num_set);

    return 0;
}