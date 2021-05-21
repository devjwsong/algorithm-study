#include <iostream>

using namespace std;

class Node {

    public:
        int num;
        Node *next;

        Node(int _num) {
            num = _num;
            next = NULL;
        }

};

class Queue {

    public:
        int size;
        Node *front;
        Node *back;

        Queue() {
            size = 0;
            front = NULL;
            back = NULL;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size == 0;
        }

        void push(int _num) {
            Node *node = new Node(_num);

            if (size == 0) {
                front = node;
                back = node;
            } else {
                back->next = node;
                back = node;
            }

            ++size;
        }

        int pop() {
            if (size == 0) {
                return -1;
            } else {
                int value = front->num;
                Node *node = front;
                front = front->next;
                
                if (front == NULL) {
                    back = NULL;
                }

                delete node;
                node = NULL;

                --size;

                return value;
            }
        }

        int getFront() {
            if (front == NULL) {
                return -1;
            } else {
                return front->num;
            }
        }

        int getBack() {
            if (back == NULL) {
                return -1;
            } else {
                return back->num;
            }
        }

};

int main() {

    int N;
    cin>>N;
    getchar();

    Queue *q = new Queue();

    for (int i=0; i<N; ++i) {
        string input;
        getline(cin, input);

        if (input.substr(0, 4) == "push") {

            int value = atoi(input.substr(5).c_str());
            q->push(value);

        } else if (input == "pop") {

            cout<<q->pop()<<"\n";

        } else if (input == "size") {

            cout<<q->getSize()<<"\n";
            
        } else if (input == "empty") {

            cout<<q->isEmpty()<<"\n";

        } else if (input == "front") {

            cout<<q->getFront()<<"\n";

        } else if (input == "back") {

            cout<<q->getBack()<<"\n";

        }
    }

    return 0;
}