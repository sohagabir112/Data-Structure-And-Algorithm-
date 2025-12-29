#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};
node *head, *newnode, *temp;

void insertAtEnd(){
    int choice;
    do{
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;

        newnode->next = nullptr;
        newnode->prev = nullptr;

        if(head == nullptr)
        {
            head = temp = newnode;
        }
        else
        {
            // temp->next = newnode;
            // newnode->prev = temp;
            // temp = newnode;
            while(temp->next != nullptr)
            {   
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
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
    insertAtEnd();
    display();

    return 0;
}