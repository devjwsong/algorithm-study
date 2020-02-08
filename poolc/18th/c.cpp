#include <iostream>
#include <vector>

using namespace std;

int N;

struct Node {
    Node (char _v, char _left, char _right) {
        v = _v;
        left = _left;
        right = _right;
    }

    char v;
    char left;
    char right;
};

vector<struct Node> graph;

void preorder(int idx) {
    printf("%c", graph[idx].v);

    if (graph[idx].left != '.') {
        preorder(graph[idx].left-'A');
    }
    
    if (graph[idx].right != '.') {
        preorder(graph[idx].right-'A');
    }   
}

void inorder(int idx) {
    if (graph[idx].left != '.') {
        inorder(graph[idx].left-'A');
    }

    printf("%c", graph[idx].v);

    if (graph[idx].right != '.') {
        inorder(graph[idx].right-'A');
    }
}

void postorder(int idx) {
    if (graph[idx].left != '.') {
        postorder(graph[idx].left-'A');
    }
    if (graph[idx].right != '.') {
        postorder(graph[idx].right-'A');
    }

    printf("%c", graph[idx].v);
}

int main() {

    scanf("%d", &N);
    getchar();

    struct Node init ('.', '.', '.');
    graph.assign(26, init);

    for (int i=1; i<=N; ++i) {
        char a, b, c;
        scanf("%c %c %c", &a, &b, &c);
        getchar();

        struct Node node(a, b, c);
        graph[a-'A'] = node;
    }

    preorder(0);
    printf("\n");

    inorder(0);
    printf("\n");

    postorder(0);
    printf("\n");

    return 0;
}