#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    //node *prev;
};
node *head, *newnode, *temp;

void deleteFromEnd(){
    temp = head;
    node *prev;
    while(temp->next != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == head) {
        head = 0;
        free(temp);
    }
    else{
        prev->next = 0;
        free(temp);
    }
}

int main(){
    deleteFromEnd();

    return 0;
}