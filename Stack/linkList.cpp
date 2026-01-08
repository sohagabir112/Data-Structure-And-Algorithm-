#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

node *top = nullptr;

void push(int x){
    node * newnode = new node;
    newnode -> data = x;
    newnode -> next = top;
    top = newnode;
}

void pop(){
    if(top == nullptr) cout<<"Empty"<<endl;
    else{
        cout<<"Popped: "<<top->data<<endl;
        top = top->next;
    }
}

void peek(){
    if(top == nullptr) cout<<"Empty"<<endl;
    else{
        cout<<"Peek element: "<<top->data<<endl;
    }
}

void display(){
    node *temp = top;
    //temp = top;
    if(top == nullptr) cout<<"Empty"<<endl;
    else{
        while(temp!=nullptr)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
}

int main(){
    int choice,data;
    do{
        cout<<"Enter your choice: "<<endl<<"1.Push"<<endl<<"2.Pop"<<endl<<"3.Peek"<<endl<<"4.Display"<<endl<<"0.Exit"<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1 : 
                cout<<"Enter data: ";
                cin>>data;
                push(data); 
                break;
            case 2 : pop();  break;
            case 3 : peek(); break;
            case 4 : display(); break;
            case 0 : break;
            default : cout<<"Invalid Optin";
        }

    }while(choice!=0);

    return 0;
}