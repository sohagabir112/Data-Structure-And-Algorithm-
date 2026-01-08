#include<iostream>
using namespace std;
#define N 5
int stack[N];
int top = -1;

void push(){
    int x;
    cout<<"Enter data: ";
    cin>>x;

    if(top == N-1) cout<<"Overflow"<<endl;
    else{
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top == -1) cout<<"Underflow"<<endl;
    else{
        int item = stack[top];
        top--;
        cout<<"Pop element: "<<item<<endl;
    }
}

void peek(){
    if(top == -1) cout<<"Underflow";
    else{
        cout<<"Peek element: "<<stack[top]<<endl;
    }
}

void display(){
    int i;
    cout<<"Remaining element in Stack: "<<endl;
    for(int i=top;i>=0;i--)
    {
        cout<<stack[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int choice;
    do{
        cout<<"Enter your choice: "<<endl<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Peek"<<endl<<"4.Display"<<endl<<"0.Exit"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1 : push(); break;
            case 2 : pop();  break;
            case 3 : peek(); break;
            case 4 : display(); break;
            case 0 : break;
            default : cout<<"Invalid Optin";
        }

    }while(choice!=0);

    return 0;
}
