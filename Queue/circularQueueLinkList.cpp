#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *newnode, *temp, *front = nullptr, *rear = nullptr;

void enQueue(int x){
    newnode = new node;
    newnode->data = x;
    newnode->next = nullptr;
    if(front == nullptr && rear == nullptr)
    {
        front = rear = newnode;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void deQueue(){
    temp = front;
    if(front == nullptr && rear == nullptr)
    {
        cout<<"Queue is empty. "<<endl;
    }
    else if(front->next == front)
    {
        cout<<"Dequeue element: "<<front->data<<endl;
        front = rear = nullptr;
        delete temp;
    }
    else{
        front = front->next;
        rear->next = front;
        delete temp;
    }
}

void peek(){
    if(front == nullptr && rear == nullptr)
    {
        cout<<"Queue is empty."<<endl;
    }
    else{
        cout<<"Peek element: "<<front->data<<endl;
    }
}

void display(){
    temp = front;
    if(front == nullptr && rear == nullptr)
    {
        cout<<"Queue is empty. "<<endl;
        return;
    }
    else{
        cout<<"Queue is: ";
        do
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp != front);
        cout<<endl;
    }
}

int main(){
    int choice , ch, data;
    do{
        cout<<"-----------MENU------------"<<endl
        <<"1.Enqueue"<<endl<<"2.Dequeue"<<endl
        <<"3.Peek"<<endl<<"4.Display"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice){
            case 1 : 
                cout<<"Enter data: ";
                cin>>data;
                enQueue(data); break;

            case 2 : deQueue(); break;
            case 3 : peek(); break;
            case 4 : display(); break;
            case 0 : exit(0); break;
            default : cout<<"Invalid Option. "<<endl;
        }
        cout<<"Do you want to continue(0,1): ";
        cin>>ch;
    }while(ch);

    return 0;
}