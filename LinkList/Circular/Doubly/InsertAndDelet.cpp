#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
};
node *newnode, *head=nullptr, *tail=nullptr, *temp;

void insertAtBegining(){
    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;

    if(head == nullptr)
    {
        head = tail = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        newnode->prev = tail;
        tail->next = newnode;
        head = newnode;
    }
}

void insertAtEnd(){
    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;

    if(head == nullptr)
    {
        head = tail = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
    }
    else{
        newnode->next = head;
        newnode->prev = tail;
        head->prev = newnode;
        tail->next = newnode;
        tail = newnode;
    }
}

int getLength(){
    int count = 1;
    temp = head;
    if(head == nullptr) return 0;
    while(temp->next != head)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtAnyPosition(){
    temp = head;
    int pos, i=1;
    cout<<"Enter Position number: ";
    cin>>pos;
    int len = getLength();
    
    if(pos<1 || pos>len+1)
    {
        cout<<"Invalid Position";
    }
    else if(pos == 1) insertAtBegining();

    else{
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;

        while(i<pos)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
    }
}

void displayList(){
    if(head == nullptr) 
    {
        cout<<"List is empty."; 
        return;
    }
    
    temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != head);
    
    cout<<endl;
}

void deleteFromBegining(){
    temp = head;
    if(head == nullptr) cout<<"List is empty";
    else if(head->next == head)
    {
        head = tail = nullptr;
        delete temp;
    }
    else{
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
}

void deleteFromEnd(){
    temp = tail;
    if(head == nullptr) cout<<"List is empty.";
    else if(head->next == head)
    {
        head = tail = nullptr;
        delete temp;
    }
    else{
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }
}

void deleteFromAnyPosition(){
    temp = head;
    int pos, i=1;
    cout<<"Enter Position number: ";
    cin>>pos;

    int len = getLength();
    if(pos<1 || pos>len+1) 
    {
        cout<<"Invalid Position";
        return;
    }
    else if(pos == 1) deleteFromBegining();
    else if(pos == len) deleteFromEnd();
    else{
        while(i<pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        
        delete temp;
    }
}

void reverseList(){
    if(head == nullptr || head->next == head)
    {
        cout<<"List is empty Or one element";
        return;
    }
    node *currentnode = head;
    node *nextnode;

    do{
        nextnode = currentnode->next;
        node *tempPtr = currentnode->next;
        currentnode->next = currentnode->prev;
        currentnode->prev = tempPtr;

        currentnode = nextnode;
    }while(currentnode != head);

    temp = head;
    head = tail;
    tail = temp;

    cout<<"List has been reversed."<<endl;
    displayList();
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

   return 0;
}
