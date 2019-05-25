#include <iostream>

using namespace std;

class Node {
    public:
        int num;
        Node *next;
        Node *prev;

        Node(int _num) {
            num = _num;
            next = NULL;
            prev = NULL;
        }
};

class Deque {
    public:
        int size;
        Node *front;
        Node *back;

        Deque() {
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

        void pushFront(int _num) {
            Node *node = new Node(_num);

            if (size == 0) {
                front = node;
                back = node;
            } else {
                front->prev = node;
                node->next = front;
                front = node;
            }

            ++size;
        }

        void pushBack(int _num) {
            Node *node = new Node(_num);

            if (size == 0) {
                front = node;
                back = node;
            } else {
                node->prev = back;
                back->next = node;
                back = node;
            }
            
            ++size;
        }

        int popFront() {
            if (front == NULL) {
                return -1;
            } else {
                int value = front->num;
                Node *node = front;
                front = front->next;

                if (front == NULL) {
                    back = NULL;
                } else {
                    front->prev = NULL;
                }

                delete node;
                node = NULL;

                --size;
                return value;
            }
        }

        int popBack() {
            if (back == NULL) {
                return -1;
            } else {
                int value = back->num;
                Node *node = back;
                back = back->prev;

                if (back == NULL) {
                    front = NULL;
                } else {
                    back->next = NULL;
                }

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

    Deque *q = new Deque();
    
    for (int i=0; i<N; ++i) {
        string input;
        getline(cin, input);

        if (input.substr(0, 10) == "push_front") {

            int value = atoi(input.substr(11).c_str());
            q->pushFront(value);

        } else if (input.substr(0, 9) == "push_back") {

            int value = atoi(input.substr(10).c_str());
            q->pushBack(value);

        } else if (input == "pop_front") {

            cout<<q->popFront()<<"\n";

        } else if (input == "pop_back") {

            cout<<q->popBack()<<"\n";

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