#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> graph[50];
int num_leaf = 0;
bool checked[50];
int e;

void search(int cur) {
    int count = 0;
    for (int i=0; i<graph[cur].size(); ++i) {
        int next = graph[cur][i];
        if (!checked[next] && next != e) {
            ++count;
            checked[next] = true;
            search(next);
        }
    }

    if (count == 0) {
        ++num_leaf;
    }
}

int main() {

    scanf("%d", &N);

    int root = 0;

    for (int i=0; i<N; ++i) {
        int p;
        scanf("%d", &p);

        if (p > -1) {
            graph[p].push_back(i);
            graph[i].push_back(p);
        } else {
            root = i;
        }
    }

    scanf("%d", &e);

    if (!checked[root] && root != e) {
        checked[root] = true;
        search(root);
    }

    printf("%d\n", num_leaf);

    return 0;
}