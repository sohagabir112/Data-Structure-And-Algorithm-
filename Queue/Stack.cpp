#include<iostream>
using namespace std;

#define N 5
int stack1[N], stack2[N];
int top1 = -1, top2 = -1;

int count = 0;

void push1(int x){
    if(top1 == N-1) cout<<"Stack is full"<<endl;
    else{
        top1++;
        stack1[top1] = x;
    }
}

void push2(int x){
    if(top2 == N-1) cout<<"Stack is full"<<endl;
    else{
        top2++;
        stack2[top2] = x;
    }
}

int pop1(){
    return stack1[top1--];
}

int pop2(){
    return stack2[top2--];
}

void display(){
    cout<<"Queue is: ";
    for(int i=0;i<=top1;i++)
    {
        cout<<stack1[i]<<" ";
    }
    cout<<endl;
}

void enqueue(int x){
    push1(x);
    count++;
}

void dequeue(){
    int i, a, b;
    if(top1 == -1 && top2 == -1) cout<<"Queue is empty"<<endl;
    else{
        for(i = 0; i<count;i++)
        {
            a = pop1();
            push2(a);
        }
        b = pop2();
        cout<<"Dequeue element: "<<b<<endl;
        count--;
        for(i=0;i<count;i++)
        {
            a = pop2();
            push1(a);
        }
    }
}


int main(){
    enqueue(5);
    enqueue(2);
    enqueue(-1);
    dequeue();
    enqueue(7);
    enqueue(8);
    enqueue(9);
    enqueue(7);
    display();
    return 0;
}