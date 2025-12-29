#include<iostream>
using namespace std;
struct node {
    int data;
    node *next;
    node *prev;
};
node *head, *newnode, *temp;

void deleteFromBegining(){
    if(head == nullptr) 
    {
        cout<<"List is empty. ";
    }
    else
    {
        temp = head;
        head = head->next;
        head->prev = nullptr;
        free(temp);
    }
}

int main(){
    deleteFromBegining();

    return 0;
}