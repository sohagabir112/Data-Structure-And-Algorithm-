#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *head, *newnode, *temp;

void getLength(){
    int count = 0;
    temp = head;
    while(temp!=0)
    {
        count++;
        temp = temp->next;
    }
    cout<<"Length is: "<<count;
}


int main(){
    getLength();

    return 0;
}