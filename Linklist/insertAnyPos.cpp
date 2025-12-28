#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
node *head = nullptr, *newnode, *temp;

int main(){
    int pos, i=1, count = 0,choice;
    do{
        newnode = new node;
        cout<<"Enter the position: ";
        cin>>pos;
        if(pos>count) cout<<"Invalid Position"<<endl;
        else{
            if(head == nullptr)
            {
                cout<<"Enter data: "<<endl;
                cin>>newnode->data;
                newnode->next = nullptr;
                head = newnode;
                count++;
            }
             
            else{
                temp = head;
                while(i<pos)
                {
                    temp = temp->next;
                    i++;
                }
                cout<<"Enter data: "<<endl;
                cin>>newnode->data;
                newnode->next = temp->next;
                temp->next = newnode;
                count++;

            }
         }
         cout<<"Do you want to continue(0,1): "<<endl;
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