#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *head, *newnode, *temp;

void deleteFromPosition(){
    node *nextnode;
    int pos, i=1;
    cout<<"Enter Position: ";
    cin>>pos;

    temp = head;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
}

int main(){
    deleteFromPosition();

    return 0;
}