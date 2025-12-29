#include<iostream>
using namespace std;
struct node {
    int data;
    node *next;
    node *prev;
};
node *head, *newnode, *temp, *tail;

void deleteFromEnd(){
    if(tail == nullptr)
    {
        cout<<"List is empty. ";
    }
    else 
    {
        temp = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;
        free(temp);
    }
}

int main(){
    deleteFromEnd();

    return 0;
}
