#include<iostream>
using namespace std;

#define N 5
int deque[N];
int front = -1, rear = -1;

void enqueueFront(int x){
    if((rear+1)%N == front){
        cout<<"Queue is full."<<endl;
        //front == rear + 1
        //front == 0 && rear = N-1
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[front] = x;
    }
    else if(front == 0)
    {
        front = N-1;
        deque[front] = x;
    }
    else{
        front--;
        deque[front] = x;
    }
}

void enqueueRear(int x){
    if((front == 0 && rear == N-1) || front == rear + 1)
    {
        cout<<"Queue is full"<<endl;
    }
    else if(front == -1 && rear == -1)
    {
        front = rear = 0;
        deque[rear] = x;
    }
    else if(rear == N-1)
    {
        rear = 0;
        deque[rear] = x;
    }
    else{
        rear++;
        deque[rear] = x;
    }
}

void display(){
    int i = front;
    if(front == -1 && rear == -1){
        cout<<"Queue is empty"<<endl;
        return;
    }
    cout<<"Queue: ";
    while(true)
    {
        cout<<deque[i]<<" ";
        if(i == rear) break;
        i = (i+1)%N;
    }
    cout<<endl;
}

void getFront(){
    if((front == 0 && rear == N-1) || front == rear + 1)
    {
        cout<<"Queue is full"<<endl;
    }
    else if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<deque[front]<<endl;
    }
}

void getRear(){
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<deque[rear]<<endl;
    }
}

void dequeueFront(){
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(front == rear) 
    {
        cout<<"Deque value: "<<deque[front]<<endl;
        front = rear = -1;
    }
    else if(front == N-1)
    {
        cout<<"Deque value: "<<deque[front]<<endl;
        front = 0;
    }
    else{
        cout<<"Deque value: "<<deque[front]<<endl;
        front++;
    }
}

void dequeRear(){
     if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if(front == rear) 
    {
        cout<<"Deque value: "<<deque[rear]<<endl;
        front = rear = -1;
    }
    else if(rear == 0)
    {
        cout<<"Deque value: "<<deque[rear]<<endl;
        rear = N-1;
    }
    else{
        cout<<"Deque value: "<<deque[rear]<<endl;
        rear--;
    }
}

int main(){
    enqueueFront(2);
    enqueueFront(5);
    enqueueRear(-1);
    enqueueRear(0);
    enqueueFront(7);
    enqueueFront(4);

    display();

    return 0; 
}