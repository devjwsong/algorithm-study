#include <iostream>

using namespace std;

int n, m;
int tree[1000001];

int Find(int a) {
    if (tree[a] == a) {
        return a;
    } else {
        tree[a] = Find(tree[a]);
        return tree[a];
    }
}

void Union(int a, int b) {
    int root_a = Find(a);
    int root_b = Find(b);

    if (root_a != root_b) {
        tree[root_a] = root_b;
    }
}

int main() {

    scanf("%d %d", &n, &m);

    for (int i=0; i<=n; ++i) {
        tree[i] = i;
    }

    for (int q=1; q<=m; ++q) {
        int p, a, b;
        scanf("%d %d %d", &p, &a, &b);

        if (p == 0) {
            Union(a, b);
        } else {
            int root_a = Find(a);
            int root_b = Find(b);
            if (root_a == root_b) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}