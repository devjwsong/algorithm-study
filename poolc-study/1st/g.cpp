#include <iostream>

using namespace std;

long long N;


int main() {
    string input;

    cin>>input>>N;
    --N;

    int len = input.size();
    long long prevLen = len;

    while(1) {
        if (prevLen*2 > N) {
            break;
        }

        prevLen *= 2;
    }


    while(1) {
        if (N < len) {
            break;
        }

        if (N < prevLen) {
            prevLen /= 2;
            continue;
        }

        --N;
        N %= prevLen;
        prevLen /= 2;
    }

    cout<<input[N]<<"\n";

    return 0;
}