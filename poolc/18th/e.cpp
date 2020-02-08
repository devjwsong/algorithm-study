#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N;

struct Node {
    Node (int _v, int _left, int _right) {
        v = _v;
        left = _left;
        right = _right;
    }

    int v;
    int left;
    int right;
};

vector<struct Node> graph;
int cols[10001];
int col = 0;
int height = 0;
pair<int, int> level[1000];

bool isChild[10001];

void inorder(int cur) {
    if (graph[cur].left != -1) {
        inorder(graph[cur].left);
    }
    
    ++col;
    cols[cur] = col;

    if (graph[cur].right != -1) {
        inorder(graph[cur].right);
    }
}

void search(int cur, int r) {
    level[r].first = max(level[r].first, cols[cur]);
    level[r].second = min(level[r].second, cols[cur]);

    int left = graph[cur].left;
    int right = graph[cur].right;

    if (right == -1 && left == -1) {
        height = max(height, r);
    }

    if (left != -1) {
        search(left, r+1);
    }

    if (right != -1) {
        search(right, r+1);
    }
}

int main() {

    scanf("%d", &N);
    struct Node init (0, 0, 0);
    graph.assign(N+1, init);

    for (int i=1; i<=N; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (b != -1) {
            isChild[b] = true;
        }

        if (c != -1) {
            isChild[c] = true;
        }

        struct Node node(a, b, c);
        graph[a] = node;
    }

    for (int i=0; i<1000; ++i) {
        level[i] = {0, INT_MAX};
    }

    int root = 0;
    for (int i=1; i<=N; ++i) {
        if (!isChild[i]) {
            root = i;
        }
    }

    inorder(root);

    search(root, 1);

    int result = 0;
    int row = 1;
    for (int i=1; i<=height; ++i) {
        int len = level[i].first - level[i].second + 1;
        if (result == len) {
            row = min(row, i);
        } else if (result < len) {
            result = len;
            row = i;
        }
    }

    printf("%d %d\n", row, result);

    return 0;
}