#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> s;
    string str;

    while(getline(cin, str)) {
        s.push_back(str);
    }

    for (int i=0; i<s.size(); ++i) {
        cout<<s[i]<<"\n";
    }

    return 0;
}