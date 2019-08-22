#include <iostream>

using namespace std;

class Point {
    public:
        int x;
        int y;

        Point(int _x, int _y) {
            x = _x;
            y = _y;
        }

        void print() {
            cout<<"(x, y): ("<<x<<", "<<y<<")"<<"\n";
        }

        Point operator + (Point& other) {
            int new_x = x + other.x;
            int nex_y = y + other.y;
            return Point(new_x, nex_y);
        }

        Point operator - (Point& other) {
            int new_x = x - other.x;
            int nex_y = y - other.y;
            return Point(new_x, nex_y);
        }

        bool operator > (Point& other) {
            return x > other.x;
        }

        bool operator < (Point& other) {
            return x < other.x;
        }

        bool operator == (Point& other) {
            return x == other.x;
        }
};

int main() {

    Point p1 (1, 2);
    Point p2 (4, 5);

    cout<<"p1 ";
    p1.print();

    cout<<"p2 ";
    p2.print();

    Point p3 = p1 + p2;
    Point p4 = p1 - p2;

    cout<<"p3 ";
    p3.print();

    cout<<"p4 ";
    p4.print();

    if (p1 > p2) {
        cout<<"p1 is bigger"<<"\n";
    } else if (p1 < p2) {
        cout<<"p2 is bigger"<<"\n";
    } else {
        cout<<"p1 and p2 is equal"<<"\n";
    }

    return 0;
}