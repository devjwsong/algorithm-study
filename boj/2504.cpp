#include <iostream>
#include <stack>

using namespace std;

int main() {

    string input;
    getline(cin, input);

    stack<int> s;

    int answer = 0;
    bool inValid = false;

    for (int i=0; i<input.size(); ++i) {

        if (input[i] == '(') {
            
            s.push(-1);

        } else if (input[i] == '[') {

            s.push(-2);

        } else if (input[i] == ')') {

            int temp = 0;
            int count = 0;

            while(1) {
                if (s.size() == 0) {
                    inValid = true;
                    break;
                }

                int top = s.top();

                if (top == -1) {
                    s.pop();

                    if (count == 0) {
                        temp = 1;
                    }

                    temp *= 2;
                    s.push(temp);
                    break;
                } else if (top == -2) {
                    inValid = true;
                    break;
                } else {
                    temp += top;
                    s.pop();
                    ++count;
                }
            }

            if (inValid) {
                break;
            }

        } else if (input[i] == ']') {

            int temp = 0;
            int count = 0;

            while(1) {
                if (s.size() == 0) {
                    inValid = true;
                    break;
                }

                int top = s.top();

                if (top == -2) {
                    s.pop();

                    if (count == 0) {
                        temp = 1;
                    }

                    temp *= 3;
                    s.push(temp);
                    break;
                } else if (top == -1) {
                    inValid = true;
                    break;
                } else {
                    temp += top;
                    s.pop();
                    ++count;
                }
            }

            if (inValid) {
                break;
            }

        }
    }

    if (!inValid) {
        while(!s.empty()) {
            int value = s.top();

            if (value == -1 || value == -2) {
                answer = 0;
                break;
            }

            answer += s.top();
            s.pop();
        }
    }

    cout<<answer<<"\n";

    return 0;
}