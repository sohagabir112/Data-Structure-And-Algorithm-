#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};
node *head = nullptr, *newnode, *temp, *tail, *currentnode, *prevnode, *nextnode;

void insertAtBegining(){
    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;

    newnode->next = head;
    newnode->prev = nullptr;

    if(head != nullptr)
        head->prev = newnode;

    head = newnode;
}

void insertAtEnd(){
    temp = head;
    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;

    newnode->next = nullptr;
    newnode->prev = nullptr;

    if(head == nullptr)
        head = newnode;
    else
    {  
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;

        //temp->next = newnode;
        //newnode->prev = temp;
        //temp = newnode;
    }

}

void insertAtAnyPosition(){
    int pos, i=1;
    temp = head;
    cout<<"Enter Position number: ";
    cin>>pos;
    while(i<pos-1 && temp != nullptr)
    {
        temp = temp->next;
        i++;
    }

    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;

    newnode->next = nullptr;
    newnode->prev = nullptr;

    if(pos<=0)
    {
        cout<<"Invalid position"<<endl;
        delete newnode;
        return;
    }
    if(temp == nullptr)
    {
        cout<<"Position out of range"<<endl;
        delete newnode;
        return;
    }

    newnode->prev = temp;
    newnode->next = temp->next;

    if(temp->next != nullptr)
        temp->next->prev = newnode;

    temp->next = newnode;
}

void deleteFromBegining(){
    if(head == nullptr)
    {
        cout<<"List is empty. ";
        return;
    }
    
    temp = head;
    head = head->next;

    if(head != nullptr)
        head->prev = nullptr;

    delete temp;
}

void deleteFromEnd(){
    if(head == nullptr)
    {
        cout<<"List is empty. ";
        return;
    }
    
    temp = head;
    while(temp->next != nullptr)
    {
        temp = temp->next;
    }
    if(temp->prev != nullptr)
        temp->prev->next = nullptr;
    else 
        head = nullptr;
    delete temp;
}

void deleteFromAnyPosition(){
    int pos,i=1;
    cout<<"Enter position number: ";
    cin>>pos;

    if(head == nullptr)
    {
        cout<<"List is empty. ";
        return;
    }
    temp = head;
    while(i<pos && temp != nullptr)
    {
        temp = temp->next;
        i++;
    }
    if(temp == nullptr)
    {
        cout<<"Position out of range. ";
        return;
    }
    if(temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    else 
        head = temp->next;
    
    if(temp->next != nullptr)
        temp->next->prev = temp->prev;

    delete temp;
}

void reverse(){
    prevnode = nullptr;
    nextnode = nullptr;
    currentnode = head;

    if(head == nullptr)
    {
        cout<<"Reverse can't possible.";
    }
    else{
        while(currentnode != nullptr)
        {
            nextnode = currentnode->next;
            currentnode->next = prevnode;
            currentnode->prev = nextnode;
            prevnode = currentnode;
            currentnode = nextnode;
        }
        head = prevnode;
    }
}

void display(){
    if(head == nullptr)
    {
        cout<<"List is empty. ";
    }
    else{
        temp = head;
        while(temp!=0)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}



int main(){
    int choice;
    while(true)
    {
            cout<<"---------MENU--------- "<<endl<<"1.Insert At Begining"<<endl
    <<"2.Insert At End"<<endl<<"3.Insert At Any Position"<<endl
    <<"4.Delete From Begining"<<endl<<"5.Delete From End"<<endl
    <<"6.Delete From Any Position"<<endl<<"7.Reverse the list"<<endl
    <<"8.Display the list"<<endl<<"0.Exit"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
        case 1 : insertAtBegining(); break;
        case 2 : insertAtEnd(); break;
        case 3 : insertAtAnyPosition(); break;
        case 4 : deleteFromBegining(); break;
        case 5 : deleteFromEnd(); break;
        case 6 : deleteFromAnyPosition(); break;
        case 7 : reverse(); break;
        case 8 : display(); break;
        case 0 : exit(0);
        default : cout<<"Invalid Option";
    }

    }

    return 0;
}