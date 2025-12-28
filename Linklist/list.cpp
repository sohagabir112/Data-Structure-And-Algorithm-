#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *head, *newnode, *temp;

int main(){
    head = 0; int choice, count = 0;
    do
    {
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;

        newnode->next = 0;
        if(head == 0) head = temp = newnode;
        else {
            temp->next = newnode;
            temp = newnode;
        }
        cout<<"Do you want to continue(0,1) :"<<endl;
        cin>>choice;
    }while(choice);
    

    temp = head;
    while(temp!=0)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
        count++;
    }
    cout<<endl<<"Total element: "<<count<<endl;

    return 0;
}