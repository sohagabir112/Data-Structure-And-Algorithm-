#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *head = nullptr, *newnode, *temp;

// int main(){
//     int choice;
//     do{
//         newnode = new node;
//         cout<<"Enter data: ";
//         cin>>newnode->data;
//         newnode->next = nullptr;

//         if(head == nullptr) head = temp = newnode;
//         else{
//             temp->next = newnode;
//             temp = newnode;
//         }
//         cout<<"Do you want to continue(0,1) :"<<endl;
//         cin>>choice;
//     }while(choice);

//     temp = head;

//     while(temp!=nullptr)
//     {
//         cout<<temp->data<<" ";
//         temp = temp->next;
//     }
//     return 0;
// }


int main(){
    int choice;
    do{
        newnode = new node;
        cout<<"Enter data: ";
        cin>>newnode->data;
        newnode->next = nullptr;

        if(head == nullptr) head = newnode;
        else{
            temp = head;
            while(temp->next != nullptr)
             {
                temp = temp->next;
             }
            temp->next = newnode;
        }
         cout<<"Do you want to continue(0,1) :"<<endl;
        cin>>choice;
    }while(choice);

    temp = head;

    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    return 0;
}