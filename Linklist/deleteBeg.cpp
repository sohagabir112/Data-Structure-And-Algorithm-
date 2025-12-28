#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};
node *head, *newnode, *temp;

void deleteFromBegining(){
    temp = head;
    head = head->next;
    free(temp);
}

int main(){
    deleteFromBegining();

    return 0;
}