#include<iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *tail = nullptr, *temp, *newnode;

void insertAtBegining() {
    newnode = new node;
    cout << "Enter data: ";
    cin >> newnode->data;

    if (tail == nullptr) {
        tail = newnode;
        tail->next = tail;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insertAtEnd() {
    newnode = new node;
    cout << "Enter data: ";
    cin >> newnode->data;

    if (tail == nullptr) {
        tail = newnode;
        tail->next = tail;
    } else {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

int getLength() {
    if (tail == nullptr) return 0;
    int count = 0;
    temp = tail->next;
    do {
        count++;
        temp = temp->next;
    } while (temp != tail->next);
    return count;
}

void insertAtAnyPosition() {
    int pos, i = 1, len = getLength();
    cout << "Enter position: ";
    cin >> pos;

    if (pos <= 0 || pos > len + 1) {
        cout << "Invalid position\n";
    } else if (pos == 1) {
        insertAtBegining();
    } else if (pos == len + 1) {
        insertAtEnd();
    } else {
        newnode = new node;
        cout << "Enter data: ";
        cin >> newnode->data;
        temp = tail->next;
        while (i < pos - 1) {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void displayList() {
    if (tail == nullptr) {
        cout << "List is empty.\n";
    } else {
        temp = tail->next;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != tail->next);
        cout << endl;
    }
}

void deleteFromBegining() {
    if (tail == nullptr) {
        cout << "List is empty.\n";
    } else {
        temp = tail->next;
        if (tail == tail->next) {
            delete temp;
            tail = nullptr;
        } else {
            tail->next = temp->next;
            delete temp;
        }
    }
}

void deleteFromEnd() {
    if (tail == nullptr) {
        cout << "List is empty.\n";
    } else {
        node *currentnode = tail->next, *prevnode = nullptr;
        if (tail->next == tail) {
            delete tail;
            tail = nullptr;
        } else {
            while (currentnode->next != tail->next) {
                prevnode = currentnode;
                currentnode = currentnode->next;
            }
            prevnode->next = tail->next;
            delete currentnode;
            tail = prevnode;
        }
    }
}

void deleteFromAnyPosition() {
    int pos, i = 1, len = getLength();
    cout << "Enter position: ";
    cin >> pos;

    if (pos <= 0 || pos > len) {
        cout << "Invalid position\n";
    } else if (pos == 1) {
        deleteFromBegining();
    } else {
        node *currentnode = tail->next, *nextnode;
        while (i < pos - 1) {
            currentnode = currentnode->next;
            i++;
        }
        nextnode = currentnode->next;
        currentnode->next = nextnode->next;
        if (nextnode == tail) {
            tail = currentnode;
        }
        delete nextnode;
    }
}

void reverseList() {
    if (tail == nullptr || tail->next == tail) {
        cout << "List is empty or has only one node.\n";
        return;
    }

    node *prev = tail, *curr = tail->next, *next = curr->next;
    do {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    } while (curr != tail->next);

    tail = tail->next;
}

int main() {
    int choice, ch;
    do {
        cout << "\n-------MENU------------" << endl
             << "1. Insert at Beginning" << endl
             << "2. Insert at End" << endl
             << "3. Insert at Any Position" << endl
             << "4. Display List" << endl
             << "5. Delete from Beginning" << endl
             << "6. Delete from End" << endl
             << "7. Delete from Any Position" << endl
             << "8. Reverse the List" << endl
             << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertAtBegining(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtAnyPosition(); break;
            case 4: displayList(); break;
            case 5: deleteFromBegining(); break;
            case 6: deleteFromEnd(); break;
            case 7: deleteFromAnyPosition(); break;
            case 8: reverseList(); break;
            case 0: exit(0);
            default: cout << "Invalid option.\n";
        }
        cout << "Do you want to continue (1: Yes / 0: No)? ";
        cin >> ch;
    } while (ch);

    return 0;
}
