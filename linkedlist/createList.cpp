
// Program to create N node linked list
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {

    Node *head, *fnode, *temp;
    int n, data;

    cin >> n >> data;

    head = new Node();
    head -> data = data;
    head -> next = NULL;
    temp = head;

    for(int i = 2; i <= n; i++) {

        cin >> data;
        fnode = new Node();
        fnode -> data = data;
        fnode -> next = NULL;
        temp -> next = fnode;
        temp = temp -> next;
    }

    while(head != NULL) {
        cout << head->data << " ";
         head = head -> next;
    }

return 0;

}