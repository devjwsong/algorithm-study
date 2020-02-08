#include <iostream>
#include <vector>

using namespace std;

int N;

struct Node {
    Node (char _me, int _left, int _right) {
        me = _me;
        left = _left;
        right = _right;
    }
    char me;
    int left;
    int right;
};

vector<struct Node> arr;

void preorder(int idx) {
    struct Node cur = arr[idx];

    if (cur.me != '\0') {
        printf("%c", cur.me);
    }

    if (cur.left != 0) {
        preorder(cur.left);
    }

    if (cur.right != 0) {
        preorder(cur.right);
    }
}

void inorder(int idx) {
    struct Node cur = arr[idx];

    if (cur.left != 0) {
        inorder(cur.left);
    }

    if (cur.me != '\0') {
        printf("%c", cur.me);
    }

    if (cur.right != 0) {
        inorder(cur.right);
    }
}

void postorder(int idx) {
    struct Node cur = arr[idx];

    if (cur.left != 0) {
        postorder(cur.left);
    }

    if (cur.right != 0) {
        postorder(cur.right);
    }

    if (cur.me != '\0') {
        printf("%c", cur.me);
    }
}

int main() {

    struct Node init ('\0', 0, 0);
    arr.assign(27, init);

    scanf("%d", &N);
    getchar();

    for (int i=1; i<=N; ++i) {
        char root, left, right;
        scanf("%c %c %c", &root, &left, &right);
        getchar();

        int left_num = 0;
        int right_num = 0;

        if (left != '.') {
            left_num = left - 'A' + 1;
        }

        if (right != '.') {
            right_num = right - 'A' + 1;
        }

        struct Node cur (root, left_num, right_num);
        arr[root-'A'+1] = cur;
    }

    preorder(1);
    printf("\n");

    inorder(1);
    printf("\n");

    postorder(1);
    printf("\n");

    return 0;
}