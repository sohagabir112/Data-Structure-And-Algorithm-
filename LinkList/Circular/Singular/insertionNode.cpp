#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *head, *tail = nullptr, *newnode, *temp;

void insertAtBegining(){
    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;
    newnode->next = nullptr;

    if(tail == nullptr)
    {
        tail = newnode;
        tail->next  = newnode;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insertAtEnd(){
    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;
    newnode->next = nullptr;

    if(tail == nullptr)
    {
        tail = newnode;
        tail->next = tail;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

int getLength(){
    int count = 0;
    if(tail == nullptr) return 0;

    temp = tail->next;
    do
    {
        count++;
        temp = temp->next;
    }while(temp != tail->next);
    
    return count;
}

void insertAtAnyPosition(){
    int pos, i=1, len;

    cout<<"Enter Position number: ";
    cin>>pos;

    len = getLength();
    if(pos<0 || pos>len+1)
    {
        cout<<"Invalid position";
    }
    else if(pos == 1) insertAtBegining();

    else if(pos == len+1) insertAtEnd();
        
    else
    {
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next = nullptr;

        temp = tail->next;
        while(i<pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = tail->next;
        tail->next = newnode;
    }
    
}

void displayList(){
    if(tail == nullptr)
    {
        cout<<"List is empty. ";
    }
    else
    {
        temp = tail->next;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != tail->next);
    }
    cout<<endl;
}

void deleteFromBegining(){
    temp = tail->next;
    if(tail == nullptr)
    {
        cout<<"List is empty. ";
    }
    else if(temp->next == temp)
    {
        tail = nullptr;
        delete temp;
    }
    else
    {
        tail->next = temp->next;
        delete temp;
    }
}

void deleteFromEnd(){
    node *currentnode, *prevnode;
    currentnode = tail->next;
    if(tail == nullptr)
    {
        cout<<"List is empty.";
    }
    else if(tail->next == currentnode)
    {
        tail == nullptr;
        delete currentnode;
    }
    else
    {
        while(currentnode->next != tail->next)
        {
            prevnode = currentnode;
            currentnode = currentnode->next;
        }
        prevnode->next = tail->next;
        tail = prevnode;
        delete currentnode;
    }
}

void deleteFromAnyPosition(){
    int pos, i=1;
    node *currentnode, *nextnode;
    currentnode = tail->next;
    cout<<"Enter Position number: "<<endl;
    cin>>pos;
    int len = getLength();

    if(pos<0 || pos>len)
    {
        cout<<"Invalid Position"<<endl;
    }
    else if(pos == 1)
    {
        deleteFromBegining();
    }
    else
    {
        while(i<pos-1)
        {
            currentnode = currentnode->next;
            i++;
        }
        nextnode = currentnode->next;
        currentnode->next = nextnode->next;
        if(nextnode == tail)
        {
            tail = currentnode;
        }
        delete nextnode;
    }
}

void reverseList(){
    node *currentnode, *prevnode, *nextnode;
    currentnode = tail->next;
    nextnode = currentnode->next;

    if(tail == nullptr || tail->next == tail)
    {
        cout<<"List is empty Or list has one node.";
        return;
    }
    
    do
    {
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
        nextnode = nextnode->next;
    }while(currentnode != tail->next);
    tail = tail->next;
    
}

int main(){
    int choice, ch;
    do{
        cout<<"-------MENU------------"<<endl
        <<"1.Insert at begining"<<endl
        <<"2.Insert at End"<<endl
        <<"3.Insert at any position"<<endl
        <<"4.Display list"<<endl
        <<"5.Delete From Begining"<<endl
        <<"6.Delete From End"<<endl
        <<"7.Delete From Any Position"<<endl
        <<"8.Reverse the list"<<endl
        <<"0.For Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1 : insertAtBegining(); break;
            case 2 : insertAtEnd(); break;
            case 3 : insertAtAnyPosition(); break;
            case 4 : displayList(); break;
            case 5 : deleteFromBegining(); break;
            case 6 : deleteFromEnd(); break;
            case 7 : deleteFromAnyPosition(); break;
            case 8 : reverseList(); break;
            case 0 : exit(0);
            default : cout<<"Invalid Option. ";
        }
        cout<<"Do you want to continue(0,1): "<<endl;
        cin>>ch;
    }while(ch);
   
}
