#include<iostream>
using namespace std;

class Queue {

    public:
    int capacity, rear, front;
    int *q;

    Queue(int c) {
        capacity = c;
        rear = 0; 
        front = 0;
        q = new int;
    }

    ~Queue() { delete[] q; }

    void Enqueue(int val);
    void Dequeue();
    int queueFront();
    void displayQueue();
};

void Queue::Enqueue(int val) {

    if(rear == capacity) {
        cout << "Queue is full" << endl;
        return;
    }
    else {
        q[rear++] = val;
        return;
    }
}

void Queue::Dequeue() {

    if(front == rear) {
        cout << "Queue is empty" << endl;
        return;
    }
    else {
        for(int i = 0; i < rear-1; i++)
            q[i] = q[i+1];
        rear--;
    }
    return;
}

int Queue::queueFront() {

    if(front == rear) {
        cout << "Queue is empty" << endl;
        return 0;
    }
    else {
        return q[front];
    }
}

void Queue::displayQueue() {

    if(front == rear) {
        cout << "Queue is empty" << endl;
        return;
    }
    else {
        for(int i = front; i < rear; i++)
            cout << q[i] << " ";
    }
    return;
}

int main() {

    Queue q(20);

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(40);
    q.Enqueue(50);
    q.displayQueue();

    q.Dequeue();
    q.Dequeue();
    q.displayQueue();
    cout << q.queueFront() << endl;

return 0;
}