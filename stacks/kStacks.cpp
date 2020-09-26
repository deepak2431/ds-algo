#include<iostream>
#include<climits>
using namespace std;

class KStack {

    int *arr, *next, *top;
    int free, n, k;

    public:
    
    KStack(int k1, int n1) {
        k = k1, n = n1;
        arr = new int[n];
        next = new int[n];
        top = new int[k];

        for(int i = 0; i < k; i++)
            top[i] = -1;
        free = 0;
        for(int i = 0; i < n-1; i++)
            next[i] = next[i+1];
        next[n-1] = -1;
    }

    void push(int data, int s);
    int pop(int sn);
    bool isEmpty(int sn) {
        return (top[sn] == -1);
    }
    bool isFull() {
        return (free == -1);
    }

};

void KStack::push(int data, int sn) {

    if(isFull()) {
        cout << "Stack is full" << endl;
        return;
    }
    int i = free;
    free = next[i];
    next[i] = top[sn];
    top[sn] = i;
    arr[i] = data;
}

int KStack::pop(int sn) {

    if(isEmpty(sn)) {
        cout << "Stack is empty" << endl;
        return INT_MAX;
    }

    int i = top[sn];
    top[sn] = next[i];
    next[i] = free;
    free = i;
    return arr[i];    
}

int main() {

    KStack ks(3, 10);

    ks.pop(2);


    ks.push(20, 2);
    ks.push(30, 2);


    ks.push(20, 2);
    ks.push(30, 2); 
    ks.push(20, 2);
    ks.push(30, 2);
    ks.push(20, 2);
    ks.push(30, 2);
    ks.push(20, 2);
    ks.push(30, 2); 
    ks.push(20, 2);
    ks.push(30, 2);
    ks.push(20, 2);
    ks.push(30, 2);



}