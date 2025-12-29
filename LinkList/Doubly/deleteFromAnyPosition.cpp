#include<iostream>
using namespace std;
struct node {
    int data;
    node *next;
    node *prev;
};
node *head, *newnode, *temp;

void deleteFromAnyPosition(){
    int pos, i=1;
    temp = head;
    cout<<"Enter Position number: ";
    cin>>pos;

    while(i<pos)
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

int main(){
    deleteFromAnyPosition();

    return 0;
}