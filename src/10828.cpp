#include <iostream>

using namespace std;

class Node {
    public:
        int num;
        Node *prev;

        Node(int _num) {
            num = _num;
            prev = NULL;
        }
};

class Stack {

    private:
        Node *top;
        int size;

    public:
        Stack() {
            top = NULL;
            size = 0;
        }

        int getSize() {
            return size;
        }

        bool empty() {
            return size == 0;
        }

        int getTop() {
            if (top == NULL) {
                return -1;
            } else {
                return top->num;
            }
        }

        void push(int input) {
            Node *node = new Node(input);
            node->prev = top;
            top = node;

            ++size;
        }

        int pop() {
            if (top == NULL) {
                return -1;
            } else {
                int value = top->num;

                Node *node = top;
                top = top->prev;
                delete node;
                node = NULL;

                --size;

                return value;
            }
        }

};

int main() {

    int N;
    cin>>N;
    getchar();

    Stack s;

    for (int i=0; i<N; ++i) {
        string command;
        getline(cin, command);

        if (command == "size") {

            cout<<s.getSize()<<"\n";

        } else if (command == "top") {

            cout<<s.getTop()<<"\n";

        } else if (command == "empty") {
            
            cout<<s.empty()<<"\n";

        } else if (command == "pop") {

            cout<<s.pop()<<"\n";

        } else if (command.substr(0, 4) == "push") {

            int value = atoi(command.substr(5).c_str());

            s.push(value);
        }
    }

    return 0;
}