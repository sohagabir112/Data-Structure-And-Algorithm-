#include<iostream>
using namespace std;

#define N 5
int queue[N];
int front = -1, rear = -1;

void enQueue(int x){
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if((rear+1)%N == front)
    {
        cout<<"Queue is full"<<endl;
    }
    else{
        rear = (rear+1)%N;
        queue[rear] = x;
    }
}

void deQueue(){
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty."<<endl;
    }
    else if(front == rear)
    {
        cout<<"Dequeue element: "<<queue[front]<<endl;
        front = rear = -1;
    }
    else{
        cout<<"Dequeue element: "<<queue[front]<<endl;
        front = (front+1)%N;
    }
}

void peek(){
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty."<<endl;
    }
    else{
        cout<<"Peek element: "<<queue[front]<<endl;
    }
}

void display(){
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty."<<endl;
    }
    else{
        int i = front;
        cout<<"Queue is: ";
        while(true)
        {
            cout<<queue[i]<<" ";
            if(i == rear) break;
            i = (i+1)%N;
        }
    }
    cout<<endl;
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