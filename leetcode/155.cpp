#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
public:
    stack<int> s;
    vector<int> ms;

    MinStack() {
    }
    
    void push(int val) {
        s.push(val);

        if (ms.empty() || ms[ms.size()-1] >= val) {
            ms.push_back(val);
        }
    }
    
    void pop() {
        int top_val = s.top();
        s.pop();

        if (ms[ms.size()-1] == top_val) {
            ms.pop_back();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ms[ms.size()-1];
    }
};


int main() {

    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    printf("%d\n", minStack->getMin()); // return -3
    minStack->pop();
    printf("%d\n", minStack->top());    // return 0
    printf("%d\n", minStack->getMin()); // return -2

    return 0;
}