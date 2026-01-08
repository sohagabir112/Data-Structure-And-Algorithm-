#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
    int height;
};

int getHeight(node *n){
    if(n == nullptr) return 0;
    return n->height;
}

int getBalance(node *n){
    if(n == nullptr) return 0;
    return getHeight(n->left) - getHeight(n->right);
}

node *createNode(int value){
    node *newnode = new node;
    newnode->data = value;
    newnode->left = newnode->right = nullptr;
    newnode->height = 1;
    return newnode;
}

node *rightRotate(node *y){
    node *x = y->left;
    node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

node *leftRotate(node *x){
    node *y = x->right;
    node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

node *insert(node *root, int key){
    if(root == nullptr) return createNode(key);

    if(key < root->data) 
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    else 
        return root;
        
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalance(root);

    if(balance > 1 && key < root->left->data)
        return rightRotate(root);

    else if(balance < -1 && key > root->right->data)
        return leftRotate(root);

    else if(balance > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    else if(balance < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inOrder(node *root){
    if(root != nullptr)
    {
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

node *minValueNode(node *newnode){
    node *current = newnode;
    while(current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

node *deleteNode(node *root, int key){
    if(!root) return root;

    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data){
        root->right = deleteNode(root->right, key);
    }
    else{
        if(!root->left  || !root->right)
        {
            node *temp = root->left ? root->right : root->right;

            if(!temp){
                temp = root;
                root = nullptr;
            }
            else{
                *root = *temp;
            }
            delete temp;
        }
        else{
            node * temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if(!root) return root;

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}

int main(){
    node *root = nullptr;
    int n , val;

    cout<<"Enter number of nodes to insert: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter value "<<i+1<<" :";
        cin>>val;
        root = insert(root, val);
    }

    cout<<endl<<"Inorder traversal of AVL Tree: ";
    inOrder(root);

       int del;
    cout << "\nEnter element to delete: ";
    cin >> del;

    root = deleteNode(root, del);

    cout << "\nAfter Deletion, In-order Traversal: ";
    inOrder(root);
    cout << endl;

    return 0;
}
