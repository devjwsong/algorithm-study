#include <iostream>
#include <queue>

using namespace std;

int T;
int A, B;

struct State {
    State(int _num) {
        num = _num;
    }

    vector<char> com;
    int num;
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

vector<char> bfs() {
    queue<struct State> q;
    struct State init(A);
    q.push(init);

    while(1) {
        if (q.empty()) {
            break;
        }

        struct State cur = q.front();
        q.pop();

        if (cur.num == B) {
            return cur.com;
        } else {
            struct State next_D (D(cur.num));
            next_D.com = cur.com;
            next_D.com.push_back('D');
            q.push(next_D);

            struct State next_S (S(cur.num));
            next_S.com = cur.com;
            next_S.com.push_back('S');
            q.push(next_S);

            struct State next_L (L(cur.num));
            next_L.com = cur.com;
            next_L.com.push_back('L');
            q.push(next_L);

            struct State next_R (R(cur.num));
            next_R.com = cur.com;
            next_R.com.push_back('R');
            q.push(next_R);
        }
    }
}

int main() {

    cin>>T;

    for (int t=1; t<=T; ++t) {
        cin>>A>>B;

        vector<char> result = bfs();

        for (int i=0; i<result.size(); ++i) {
            cout<<result[i];
        }
        cout<<"\n";
    }

    return 0;
}