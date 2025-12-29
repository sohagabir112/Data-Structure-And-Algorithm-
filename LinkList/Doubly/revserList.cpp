#include<iostream>
using namespace std;
struct node {
    int data;
    node *next;
    node *prev;
};
node *head, *newnode, *temp, *tail;

void reverseList(){
    node *currentnode, *nextnode;
    if(head == nullptr)
    {
        cout<<"Reverse can't possible";
    }
    else
    {
        currentnode = head;
        while(currentnode != nullptr)
        {
            nextnode = currentnode->next;
            currentnode->next = currentnode->prev;
            currentnode->prev = nextnode;
            currentnode = nextnode;
        }
        currentnode = head;
        head = tail;
        tail = currentnode;
    }
}

int main(){
    reverseList();

    return 0;
}