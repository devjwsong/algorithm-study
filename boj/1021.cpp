#include <iostream>
#include <deque>
#include <utility>

using namespace std;

deque<int> dq;

void op2() {
    int value = dq.front();
    dq.pop_front();
    dq.push_back(value);
}

void op3() {
    int value = dq.back();
    dq.pop_back();
    dq.push_front(value);
}

int find(int input) {
    deque<int> cpy = dq;

    int index = 0;
    while(1) {
        if (cpy.front() == input) {
            break;
        }

        int value = cpy.front();
        cpy.pop_front();
        cpy.push_back(value);

        ++index;
    }

    return index;
}

int main() {

    int N, M;
    scanf("%d %d", &N, &M);

    for (int i=1; i<=N; ++i) {
        dq.push_back(i);
    }

    int count = 0;

    for (int i=0; i<M; ++i) {
        int input;
        scanf("%d", &input);

        int index = find(input);

        if (index <= dq.size()/2) {
            while(1) {
                if (dq.front() == input) {
                    dq.pop_front();
                    break;
                } else {
                    op2();
                    ++count;
                }
            }
        } else {
            while(1) {
                if (dq.front() == input) {
                    dq.pop_front();
                    break;
                } else {
                    op3();
                    ++count;
                }
            }
        }
    }

    printf("%d\n", count);

    return 0;
}