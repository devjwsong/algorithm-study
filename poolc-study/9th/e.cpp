#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int T;
int A, B;

struct State {
    State (int _cur, int _prev, char _com) {
        cur = _cur;
        prev = _prev;
        com = _com;
    }

    int cur;
    int prev;
    char com;
};

int D(int input) {
    return (2*input)%10000;
}

int S(int input) {
    if (input == 0) {
        return 9999;
    } else {
        return input-1;
    }
}

int L(int input) {
    if (input >= 1000) {
        int a = input / 1000;
        int b = input % 1000;
        return b*10 + a;
    } else {
        return input * 10;
    }
}

int R(int input) {
    if (input % 10 == 0) {
        return input / 10;
    } else {
        int b = input % 10;
        return b * 1000 + input / 10;
    }
}

void bfs() {
    
    struct State init(-1, -1, '?');
    vector<struct State> memo (10000, init);

    queue<struct State> q;
    init.cur = A;
    q.push(init);

    while(1) {
        if (q.empty()) {
            break;
        }

        struct State cur = q.front();
        q.pop();

        if (cur.cur == B) {
            break;
        } else {
            for (int i=0; i<4; ++i) {
                if (i == 0) {
                    int new_num = D(cur.cur);
                    if (memo[new_num].cur == -1) {
                        struct State next (new_num, cur.cur, 'D');
                        q.push(next);
                        memo[new_num] = next;
                    }
                } else if (i == 1) {
                    int new_num = S(cur.cur);
                    if (memo[new_num].cur == -1) {
                        struct State next (new_num, cur.cur, 'S');
                        q.push(next);
                        memo[new_num] = next;
                    }
                } else if (i == 2) {
                    int new_num = L(cur.cur);
                    if (memo[new_num].cur == -1) {
                        struct State next (new_num, cur.cur, 'L');
                        q.push(next);
                        memo[new_num] = next;
                    }
                } else if (i == 3) {
                    int new_num = R(cur.cur);
                    if (memo[new_num].cur == -1) {
                        struct State next (new_num, cur.cur, 'R');
                        q.push(next);
                        memo[new_num] = next;
                    }
                }
            }
        }
    }

    string answer = "";
    int cur = B;
    while(1) {
        if (cur == A) {
            break;
        }

        answer = memo[cur].com + answer;
        cur = memo[cur].prev;
    }

    cout<<answer<<"\n";
}

int main() {

    cin>>T;

    for (int t=1; t<=T; ++t) {
        cin>>A>>B;

        struct State init(-1, -1, '?');

        bfs();

    }

    return 0;
}