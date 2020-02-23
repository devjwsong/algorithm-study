#include <iostream>
#include <climits>

using namespace std;

const long long INF = LONG_LONG_MAX;

int N;
long long answer = -INT_MAX;

string input;

long long cal(long long a, long long b, char op) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '*') {
        return a * b;
    }
}

void process(int idx, long long out_value, char out_op, long long in_value, char in_op) {
    if (idx >= N) {
        // cout<<idx<<" "<<out_value<<" "<<out_op<<" "<<in_value<<" "<<in_op<<endl;
        if (in_op == '.') {
            if (in_value == -INF) {
                answer = max(answer, out_value);
            } else {
                answer = max(answer, cal(out_value, in_value, out_op));
            }
        } else {
            answer = max(answer, cal(out_value, in_value, out_op));
        }
    } else {
        int cur_value = input[idx] - '0';
        char cur_op = '.';
        if (idx+1 < N) {
            cur_op = input[idx+1];
        }

        if (in_op == '.') {
            process(idx+2, cal(out_value, cur_value, out_op), cur_op, -INF, '.');
            process(idx+2, out_value, out_op, cur_value, cur_op);
        } else {
            process(idx+2, cal(out_value, cal(in_value, cur_value, in_op),out_op), cur_op, -INF, '.');
        }
    }
}

int main() {

    cin>>N;
    getchar();

    getline(cin, input);
    
    process(0, 0, '+', -INF, '.');

    cout<<answer<<"\n";

    return 0;
}