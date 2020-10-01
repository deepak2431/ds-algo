// To delete a node from a binary tree

void deleteDeepest(struct Node *root, struct Node *d_node) {
    
    queue<struct Node*>q;
    q.push(root);
    while(!q.empty()) {
        struct Node *temp = q.front();
        q.pop();
        if(temp->right) {
            if(temp->right == d_node) {
                temp->right = NULL;
                delete d_node;
                return;
            }
            else
                q.push(temp->right);
        }
        if(temp->left){
            if(temp->left == d_node) {
                temp->left = NULL;
                delete d_node;
                return;
            }
            else
                q.push(temp->left);
            
        }
    }
    return;
}
void deletionBT(struct Node* root, int key)
{
    // code here
    if (root == NULL) 
        return ; 
  
    if (root->left == NULL && root->right == NULL) { 
        if (root->data == key) 
            return;
    }
    struct Node *temp, *key_node;
    queue<struct Node*>q;
    q.push(root);
    while(!q.empty()) {
        temp = q.front();
        q.pop();
        if(temp->data == key) 
            key_node = temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    if(key_node != NULL) {
        int x = temp->data;
        deleteDeepest(root,temp);
        key_node->data = x;
        
    }
    return;
}