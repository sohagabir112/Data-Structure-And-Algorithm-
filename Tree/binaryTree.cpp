#include<iostream>
using namespace std;

struct node{
    int data;
    node *left;
    node *right;
};


node *create(){
    int x;
    cout<<"Enter Data(-1 for no node): "<<endl;
    cin>>x;

    if(x == -1) return nullptr;

    node *newnode = new node;
    newnode->data = x;

    cout<<"Enter left child of: "<<x<<endl;
    newnode->left = create();

    cout<<"Enter right child: "<<x<<endl;
    newnode->right = create();

    return newnode;
}

void display(node *root ,int space = 0){
    int height = 10;
    if(root == nullptr) return;
    
    space += height;

    display(root->right, space);

    cout<<endl;
    for(int i=height; i<space; i++)
    {
        cout<<" ";
    }
    cout<<root->data<<"\n";

    display(root->left, space);
}

int main(){
    node *root = create();

    cout<<endl<<"Binary Tree Structure :  "<<endl;
    display(root);

    return 0;
}