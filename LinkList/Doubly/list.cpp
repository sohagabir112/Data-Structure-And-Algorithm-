#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};
node *head, *newnode, *temp;

void create(){
    int choice;
    head = nullptr;
    do
    {
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next = nullptr;
        newnode->prev = nullptr;
        
        if(head == nullptr) 
        {
            head = temp = newnode;
        }
        else{
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
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
    create();
    display();

    return 0;
}