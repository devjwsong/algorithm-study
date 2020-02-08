#include <iostream>
#include <stack>

using namespace std;

int T;

int main() {

    cin>>T;
    getchar();

    for (int t=1; t<=T; ++t) {
        string input;
        getline(cin, input);

        stack<char> s;
        string answer = "";

        for (int i=0; i<input.size(); ++i) {
            char cur = input[i];
            if (cur == '(') {
                s.push(cur);
            } else {
                if (!s.empty()) {
                    s.pop();
                } else {
                    answer = "NO";
                    break;
                }
            }
        }

        if (s.empty() && answer == "") {
            answer = "YES";
        } else {
            answer = "NO";
        }

        cout<<answer<<"\n";
    }

    return 0;
}