#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};

node *create(){
    int x;
    cout<<"Enter data(-1 for no node): ";
    cin>>x;
    if(x == -1) return nullptr;

    node *newnode = new node;
    newnode->data = x;

    cout<<"Enter left child(-1 for no node): "<<x<<endl;
    newnode->left = create();

    cout<<"Enter right child(-1 for no node): "<<x<<endl;
    newnode->right = create();

    return newnode;
}

void preOrder(node *root){
    if(root == nullptr) return;

    cout<<root->data<<" ";

    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node *root){
    if(root == nullptr) return;

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node *root){
    if(root == nullptr) return;

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){
    node *root = create();

    cout<<"Preorder is: ";
    preOrder(root);
    cout<<endl;
    cout<<"Inorder is: ";
    inOrder(root);
    cout<<endl;
    cout<<"PostOrder is: ";
    postOrder(root);

    return 0;
}