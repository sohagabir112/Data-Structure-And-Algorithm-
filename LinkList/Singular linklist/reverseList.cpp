#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *head, *newnode, *temp, *prevnode, *currentnode, *nextnode;

void reverse(){
    prevnode = 0;
    currentnode = nextnode = head;

    while(nextnode!=0)
    {
        nextnode = nextnode->next;
        currentnode->next = prevnode;
        prevnode = currentnode;
        currentnode = nextnode;
    }
    head = prevnode;
}

int main(){
    reverse();

    return 0;
}