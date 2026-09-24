#include <iostream>
#include <string>
#include <algorithm>
#define MAX 5
using namespace std;

class Stack {
private:
    int stk[MAX][2];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isStackEmpty() {
        return top == -1;
    }

    bool isStackFull() {
        return top == MAX - 1;
    }

    void push(int val) {

    }

    int pop() {
        if (!isStackEmpty()) {
            return stk[top--][0];
        } else {
            cout << "Stack Empty\n";
            return -1;
        }
    }

    void printStack() {
        cout << "\nStack elements:\n";
        for (int i = top; i >= 0; i--) {
            cout << stk[i][0] << "\n";
        }
    }

    void minStack() {
        if (!isStackEmpty()) {
            cout << "Min: " << stk[top][1] << "\n";
        }
    }
};

int main() {
    Stack s;
    s.push(2);
    s.push(3);
    s.push(9);
    s.push(1);

    s.printStack();
    s.minStack();

    s.pop();

    s.printStack();
    s.minStack();

    return 0;
}