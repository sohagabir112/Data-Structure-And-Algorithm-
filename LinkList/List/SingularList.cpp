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

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning() {
        int value;
        cout << "Enter data: ";
        cin >> value;

        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd() {
        int value;
        cout << "Enter data: ";
        cin >> value;

        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtAnyPosition() {
        int pos, value, i = 1;
        cout << "Enter position number: ";
        cin >> pos;

        if (pos == 1) {
            insertAtBeginning();
            return;
        }

        Node* temp = head;
        while (i < pos - 1 && temp != nullptr) {
            temp = temp->next;
            i++;
        }

        if (temp == nullptr) {
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

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = nullptr;
        delete temp;
    }

    void deleteFromAnyPosition() {
        int pos, i = 1;
        cout << "Enter position number: ";
        cin >> pos;

        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        while (i < pos - 1 && temp != nullptr) {
            temp = temp->next;
            i++;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    void getLength() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        cout << "Length of this list is: " << count << endl;
    }

    void reverse() {
        Node* prevNode = nullptr;
        Node* currentNode = head;
        Node* nextNode = nullptr;

        while (currentNode != nullptr) {
            nextNode = currentNode->next;
            currentNode->next = prevNode;
            prevNode = currentNode;
            currentNode = nextNode;
        }

        head = prevNode;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    int choice;

    while (true) {
        cout << "---------MENU---------" << endl
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
