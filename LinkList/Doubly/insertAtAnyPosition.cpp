#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};
node *head, *newnode, *temp;

void insertAtAnyPosition(){
    int count = 0, pos, i = 1,choice;
    do{
    cout<<"Enter Postion number: ";
    cin>>pos;
    if(count == 0)
    {
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next = nullptr;
        newnode->prev = nullptr;
        head = temp = newnode;
        count++;
    }
    else if(count == 1)
    {
          newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next = nullptr;
        newnode->prev = nullptr;
        temp = head;
        temp->next = newnode;
        newnode->prev = temp;
        temp = newnode;
        count++;
    }
    else
    {
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next = nullptr;
        newnode->prev = nullptr;

        while(i<pos-1 && temp!= nullptr)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
    cout<<"Do you want to continue(0,1): "<<endl;
    cin>>choice;
    }while(choice);
    
}

void display(){
    temp =  head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){
    insertAtAnyPosition();
    display();

    return 0;
}