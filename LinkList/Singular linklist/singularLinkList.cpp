#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head = nullptr, *newnode, *temp;

void insertAtBegining(){
    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd(){
    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;
    newnode->next = nullptr;

    if(head == nullptr) head = newnode;
    else{
        temp = head;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode; 
    }
    free(temp);
}

void insertAtAnyPosition(){
    int pos,i=1;
    cout<<"Enter Position number: "<<endl;
    cin>>pos;
    if(pos == 1) 
    {
        insertAtBegining();
        return;
    }
    temp = head;
    while(i<pos-1 && temp != nullptr)
    {
        temp = temp->next;
        i++;
    }
    if(temp == nullptr)
    {
        cout<<"Invalid position"<<endl;
    }
    newnode = new node;
    cout<<"Enter data: ";
    cin>>newnode->data;
    newnode->next = temp->next;
    temp->next = newnode;
    
    free(temp);
}

void deleteFromBegining(){
    if(head == nullptr)
    {
        cout<<"List is empty."<<endl;
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}

void deleteFromEnd(){
    if(head == nullptr)
    {
        cout<<"List is empty."<<endl;
        return;
    }
    else if(head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }
    temp = head;
    node *prev;
    while(temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = nullptr;
    free(temp);

}

void deleteFromAnyPosition(){
    int pos, i = 1;
    node * nextnode;
    cout<<"Enter Position number: "<<endl;
    cin>>pos;
    if(pos == 1)
    {
        deleteFromBegining();
        return;
    }
    temp = head;
    while(i<pos-1 && temp->next != nullptr)
    {
        temp = temp->next;
        i++; 
    }
    if(temp->next == nullptr)
    {
        cout<<"Invalid position "<<endl;
        return;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}

void getLength(){
    int count = 0;
    temp = head;
    while(temp != nullptr)
    {
        temp = temp->next;
        count++; 
    }
    cout<<"Length of this list is: "<<count<<endl;
}

void reverse(){
    node *prevnode = nullptr, *currentnode = head, *nextnode;
    //currentnode = nextnode = head;

    while(nextnode!=nullptr){
        nextnode = currentnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}

void display(){
    if(head == nullptr)
    {
        cout<<"List is empty. "<<endl;
        return;
    }
    temp = head;
    while(temp != nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    int choice;
    while(true)
    {
            cout<<"---------MENU--------- "<<endl<<"1.Insert At Begining"<<endl
    <<"2.Insert At End"<<endl<<"3.Insert At Any Position"<<endl
    <<"4.Delete From Begining"<<endl<<"5.Delete From End"<<endl
    <<"6.Delete From Any Position"<<endl<<"7.Length of list"<<endl
    <<"8.Reverse the list"<<endl<<"9.Display the list"<<endl<<"0.Exit"<<endl;

    cout<<"Enter your choice: ";
    cin>>choice;

    switch(choice){
        case 1 : insertAtBegining(); break;
        case 2 : insertAtEnd(); break;
        case 3 : insertAtAnyPosition(); break;
        case 4 : deleteFromBegining(); break;
        case 5 : deleteFromEnd(); break;
        case 6 : deleteFromAnyPosition(); break;
        case 7 : getLength(); break;
        case 8 : reverse(); break;
        case 9 : display(); break;
        case 0 : exit(0);
        default : cout<<"Invalid Option";
    }

    }

    return 0;
    
}