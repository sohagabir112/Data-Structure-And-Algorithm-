#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *tail, *temp, *newnode;

void createList(){
    int choice;
    tail = nullptr;
    do{
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next = nullptr;

        if(tail == nullptr)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else{
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        cout<<"Do you want to continue(0,1): "<<endl;
        cin>>choice;
      //  cout<<tail->next->data<<endl;
    }while(choice);
}

void displayList(){
    temp = tail->next;
    if(tail == nullptr)
    {
        cout<<"List is empty. ";
        return;
    }
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail->next);
    cout<<endl;
}

int main(){
    createList();
    displayList();

    return 0;
}