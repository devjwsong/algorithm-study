#include <iostream>
#include <stack>

using namespace std;

int main() {

    int T;
    cin>>T;
    getchar();

    stack<char> s;

    for (int i=0; i<T; ++i) {
        string input;
        getline(cin, input);

        string answer;

        for (int j=0; j<input.size(); ++j) {
            if (input[j] == '(') {
                s.push('(');
            } else if (input[j] == ')') {
                if (s.size() == 0) {
                    answer = "NO";
                    break;
                } else {
                    s.pop();
                }
            }

            if (j == input.size()-1) {
                if (s.size() != 0) {
                    answer = "NO";
                } else {
                    answer = "YES";
                }
            }
        }

        cout<<answer<<"\n";

        while(!s.empty()) {
            s.pop();
        }
    }

    return 0;
}