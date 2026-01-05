#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning() {
        int value;
        cout << "Enter data: ";
        cin >> value;
        Node* newNode = new Node(value);

        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }

    void insertAtEnd() {
        int value;
        cout << "Enter data: ";
        cin >> value;
        Node* newNode = new Node(value);

        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void insertAtAnyPosition() {
        int pos, value;
        cout << "Enter position: ";
        cin >> pos;

        if (pos == 1) {
            insertAtBeginning();
            return;
        }

        Node* temp = head;
        int i = 1;
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }

        if (i != pos - 1) {
            cout << "Invalid position" << endl;
            return;
        }

        cout << "Enter data: ";
        cin >> value;
        Node* newNode = new Node(value);

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* last = head;

        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        delete temp;
    }

    void deleteFromAnyPosition() {
        int pos;
        cout << "Enter position: ";
        cin >> pos;

        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        int i = 1;

        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }

        if (temp->next == head || temp == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    void getLength() {
        if (head == nullptr) {
            cout << "Length: 0" << endl;
            return;
        }

        int count = 1;
        Node* temp = head;

        while (temp->next != head) {
            count++;
            temp = temp->next;
        }

        cout << "Length: " << count << endl;
    }

    void reverse() {
    if (head == nullptr || head->next == head) return;

    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    Node* last = head;

    // Find the last node
    while (last->next != head) {
        last = last->next;
    }

    Node* tail = head;  // Old head becomes the new tail

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    head = prev;
    tail->next = head;  // Reconnect tail to new head
}


    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
    int choice;

    while (true) {
        cout << "\n---------MENU---------" << endl
             << "1. Insert At Beginning" << endl
             << "2. Insert At End" << endl
             << "3. Insert At Any Position" << endl
             << "4. Delete From Beginning" << endl
             << "5. Delete From End" << endl
             << "6. Delete From Any Position" << endl
             << "7. Length of List" << endl
             << "8. Reverse the List" << endl
             << "9. Display the List" << endl
             << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: list.insertAtBeginning(); break;
            case 2: list.insertAtEnd(); break;
            case 3: list.insertAtAnyPosition(); break;
            case 4: list.deleteFromBeginning(); break;
            case 5: list.deleteFromEnd(); break;
            case 6: list.deleteFromAnyPosition(); break;
            case 7: list.getLength(); break;
            case 8: list.reverse(); break;
            case 9: list.display(); break;
            case 0: exit(0);
            default: cout << "Invalid option." << endl;
        }
    }

    return 0;
}
