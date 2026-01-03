#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *head, *newnode, *temp;

void createNode(){
    int choice;
    head = nullptr;
    do{
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next = nullptr;

        if(head == nullptr)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            temp->next = head;
        }
        cout<<"Do you want to continue(0,1): "<<endl;
        cin>>choice;
    }while(choice);
}

void displayList(){
    temp = head;
    if(head == nullptr)
    {
        cout<<"List is empty. ";
    }
    else
    {
        temp = head;
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != head);
        cout<<endl;
    }
}

int main(){
    createNode();
    displayList();

    return 0;
}