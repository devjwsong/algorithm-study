#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<int> seq;

int main() {

    scanf("%d %d", &N, &K);

    for (int i=1; i<=N; ++i) {
        seq.push(i);
    } 

    printf("<");

    int count = 0;
    while(!seq.empty()) {
        int front = seq.front();
        seq.pop();
        ++count;

        if (count == K) {
            count = 0;
            printf("%d", front);

            if (!seq.empty()) {
                printf(", ");
            }
        } else {
            seq.push(front);
        }
    }

    printf(">\n");

    return 0;
}