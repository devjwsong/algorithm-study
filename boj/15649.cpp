#include <iostream>

using namespace std;

int N, M;
bool visited[9];

void dfs(int cur, int count, int* arr) {
    arr[count] = cur;

    if (count == M) {
        for (int i=1; i<=count; ++i) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i=1; i<=N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            dfs(i, count + 1, arr);
            visited[i] = false;
        }
    }
}

int main() {

    scanf("%d %d", &N, &M);

    for (int i=1; i<=N; ++i) {
        visited[i] = true;
        int arr[N+1] = {0, };
        dfs(i, 1, arr);
        visited[i] = false;
    }

    return 0;
}