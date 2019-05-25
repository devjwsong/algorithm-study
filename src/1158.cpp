#include <iostream>
#include <queue>

using namespace std;

int main() {

    int N, K;
    scanf("%d %d", &N, &K);

    queue<int> q;

    for (int i=1; i<=N; ++i) {
        q.push(i);
    }

    printf("<");

    while(1) {
        int count = 0;

        while(count < K-1) {
            int front = q.front();
            q.pop();
            q.push(front);

            ++count;
        }

        printf("%d", q.front());
        q.pop();

        if (!q.empty()) {
            printf(", ");
        } else {
            break;
        }
    }

    printf(">\n");

    return 0;
}