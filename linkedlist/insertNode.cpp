// Program to insert node at different position in a linked list
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class InsertNode {

    public:

        void insertAtBegin(Node **head, int data);
        void insertInbetween(Node **prev_node, int data);
        void appendNode(Node **head, int data);
        void displayList(Node **head);
};

void InsertNode::insertAtBegin(Node **head, int data) {

    Node *fnode;
    fnode = new Node();
    fnode -> data = data;
    fnode -> next = *head;
    *head = fnode;
}

void InsertNode::insertInbetween(Node **prev_node, int data) {

    Node *fnode;
    fnode = new Node();
    fnode -> data = data;
    fnode -> next = *prev_node;
    *prev_node = fnode;

}
 
void InsertNode::appendNode(Node **head, int data) {

    Node *temp = *head, *fnode;
    fnode = new Node();
    fnode -> data = data;
    fnode -> next = NULL;

    while(temp -> next != NULL)
        temp = temp -> next;
    
    temp->next = fnode;
}

void InsertNode::displayList(Node **head) {

    Node *temp = *head;
    while(temp != NULL) {
        cout << temp-> data << " ";
        temp = temp -> next;
    }
}

int main() {

    Node *head = NULL;
    InsertNode in;

    in.insertAtBegin(&head, 5);
    in.insertAtBegin(&head, 10);
    in.insertAtBegin(&head, 15);

    //in.displayList(&head);

    in.insertInbetween(&head->next->next, 100);

    in.appendNode(&head, 20);
    in.appendNode(&head, 50);

    in.displayList(&head);

return 0;
}
