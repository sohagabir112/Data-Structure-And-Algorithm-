#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};
node *head = nullptr, *tail, *newnode, *temp;

void createNode(){
    int choice;
    do{
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        
        if(head == nullptr)
        {
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            tail->next = newnode;
            newnode->prev = tail;
            head->prev = newnode;
            tail = newnode;
        }
        cout<<"Do you want to continue(0,1): ";
        cin>>choice;
    }while(choice);
}

void displayList(){
    temp = head;
    if(head == nullptr)
    {
        cout<<"List is empty. ";
    }
    else{
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != tail->next);
        cout<<endl;
    }
}

int main(){
    createNode();
    displayList();

    return 0;
}