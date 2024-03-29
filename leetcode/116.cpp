#include <iostream>

using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    void search(Node* root) {
        if (root == nullptr) return;

        if (root->left != nullptr && root->right != nullptr) {
            root->left->next = root->right;
            if (root->next != nullptr) {
                root->right->next = root->next->left;
            }

            search(root->left);
            search(root->right);
        }
    }

    Node* connect(Node* root) {
        search(root);

        return root;
    }
};