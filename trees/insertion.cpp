/* Use the level order traversal method to insert node
   Time complexity O(h), where h is the height of the tree
*/

#include<iostream> 
#include<queue>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data) {

    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL; 
}

Node *insertNode(Node *root, int data) {

    if(root == NULL) {
        Node *root = createNode(data);
        return root;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        if(temp->left == NULL) {
            temp->left = createNode(data);
            return root;
        }
        else if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
        else if(temp->right == NULL) {
            temp->right = createNode(data);
            return root;
        }
    }
}

void inorder(Node* temp) {

    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}
 
int main() {

    Node* root = createNode(10);
    root->left = createNode(11);
    root->left->left = createNode(7);
    root->right = createNode(9);
    root->right->left = createNode(15);
    root->right->right = createNode(8);
 
    cout << "Inorder traversal before insertion: ";
    inorder(root);
    cout << endl;
 
    int key = 12;
    root = insertNode(root, key);
 
    cout << "Inorder traversal after insertion: ";
    inorder(root);
    cout << endl;
 
    return 0;
}