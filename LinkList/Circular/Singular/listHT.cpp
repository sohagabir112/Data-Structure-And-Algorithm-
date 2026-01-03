#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *head, *newnode, *tail, *temp;

void createList(){
    int choice;
    head = nullptr;
    do
    {
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next = nullptr;

        if(head == nullptr)
        {
            head = tail = newnode;
            //tail->next = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
        cout<<"Do you want to continue(0,1): "<<endl;
        cin>>choice;
    }while(choice);
}

void displayList(){
    if(head == nullptr)
    {
        cout<<"List is empty. ";
    }
    else{
        temp = head;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != head);
    }
}

int main(){
    createList();
    displayList();

    return 0;
}