#include <iostream>
#include <algorithm>

using namespace std;

string S;

bool isPalin(string str) {
    for (int i=0; i<str.size()/2; ++i) {
        if (str[i] != str[str.size()-1-i]) {
            return false;
        }
    }

    return true;
}

int main() {

    cin>>S;

    int answer = 0;
    int count = 1;
    string new_S = S;

    while(1) {
        if (isPalin(new_S)) {
            answer = new_S.size();
            break;
        }

        string attached = S.substr(0, count);
        reverse(attached.begin(), attached.end());
        new_S = S + attached;
        ++count;
    }
    // cout<<new_S<<endl;
    cout<<answer<<"\n";

    return 0;
}