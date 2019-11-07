#include <iostream>
#include <stack>

using namespace std;

int N;
string input;
int answer = 0;

int calculate(string line) {
    stack<int> s;
    s.push(line[0]-'0');

    for (int i=1; i<line.size(); ++i) {
        if (line[i] >= 48 && line[i] <= 57) {
            int oper = s.top();
            s.pop();
            int n = s.top();
            s.pop();

            int next = 0;
            if (oper == -1) {
                next = n + (line[i]-'0');
            } else if (oper == -2) {
                next = n - (line[i]-'0');
            } else if (oper == -3) {
                next = n * (line[i]-'0');
            }

            s.push(next);
        } else {
            if (line[i] == '+') {
                s.push(-1);
            } else if (line[i] == '-') {
                s.push(-2);
            } else if (line[i] == '*') {
                s.push(-3);
            }
        }
    }

    return s.top();
}

void dfs(string cur) {
    
}

int main() {

    cin>>N;
    getchar();
    getline(cin, input);

    

    return 0;
}