#include<iostream>

using namespace std;

#define MAX 1000

class Stack {

    int top;
    public:
    int a[MAX];
    
    Stack() {
        top = -1;
    }

    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) {

    if(top >= MAX - 1) {
        cout << "Stack Overflow" << endl;
        return false;
    }

    else {
        top++;
        a[top] = x;
        cout << "Element pushed successfully" << endl;
        return true;
    }
}

int Stack::pop() {

    if(top == -1) {
        cout << "Stack Underflow" << endl;
        return 0;
    }

    else {
        int val = a[top];
        top--;
        return val;
    }
}

int Stack::peek() {

    if(top == -1) {
        cout << " Stack Underflow" << endl;
        return 0;
    }
    else {
        return a[top];
    }
}

bool Stack::isEmpty() {

    return (top < 0);
}   

int main() {

    Stack s;
    s.push(10);
    cout << s.pop() << endl;
    s.push(20);
    s.push(20);
    cout << s.pop() << endl;
    cout << s.peek() << endl;
    cout  << s.isEmpty() << endl;
}
