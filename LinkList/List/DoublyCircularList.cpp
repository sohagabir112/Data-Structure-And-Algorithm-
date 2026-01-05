#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) {
        data = value;
        next = prev = nullptr;
    }
};

class DoublyCircularLinkedList {
private:
    Node* head;

public:
    DoublyCircularLinkedList() {
        head = nullptr;
    }

    void insertAtBeginning() {
        int value;
        cout << "Enter data: ";
        cin >> value;
        Node* newNode = new Node(value);

        if (head == nullptr) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }

        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;
        head->prev = newNode;
        last->next = newNode;
        head = newNode;
    }

    void insertAtEnd() {
        int value;
        cout << "Enter data: ";
        cin >> value;
        Node* newNode = new Node(value);

        if (head == nullptr) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
            return;
        }

        Node* last = head->prev;

        last->next = newNode;
        newNode->prev = last;
        newNode->next = head;
        head->prev = newNode;
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
            cout << "Invalid position." << endl;
            return;
        }

        cout << "Enter data: ";
        cin >> value;
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
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

        Node* last = head->prev;
        Node* temp = head;

        head = head->next;
        head->prev = last;
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

        Node* last = head->prev;
        Node* secondLast = last->prev;

        secondLast->next = head;
        head->prev = secondLast;

        delete last;
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
        while (i < pos && temp->next != head) {
            temp = temp->next;
            i++;
        }

        if (temp == head || i != pos) {
            cout << "Invalid position." << endl;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void displayForward() {
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

    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* last = head->prev;
        Node* temp = last;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != last);
        cout << endl;
    }

    void reverse() {
    if (head == nullptr || head->next == head)
        return;

    Node* current = head;
    Node* temp = nullptr;

    // Swap next and prev for each node
    do {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    } while (current != head);

    // Move head to the last node, which is the new head
    head = head->next;
    }


    void getLength() {
        if (head == nullptr) {
            cout << "Length: 0" << endl;
            return;
        }

        int count = 0;
        Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);

        cout << "Length: " << count << endl;
    }
};

int main() {
    DoublyCircularLinkedList list;
    int choice;

    while (true) {
        cout << "\n------ MENU ------\n"
             << "1. Insert At Beginning\n"
             << "2. Insert At End\n"
             << "3. Insert At Any Position\n"
             << "4. Delete From Beginning\n"
             << "5. Delete From End\n"
             << "6. Delete From Any Position\n"
             << "7. Display Forward\n"
             << "8. Display Backward\n"
             << "9. Reverse the List\n"
             << "10. Get Length\n"
             << "0. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: list.insertAtBeginning(); break;
            case 2: list.insertAtEnd(); break;
            case 3: list.insertAtAnyPosition(); break;
            case 4: list.deleteFromBeginning(); break;
            case 5: list.deleteFromEnd(); break;
            case 6: list.deleteFromAnyPosition(); break;
            case 7: list.displayForward(); break;
            case 8: list.displayBackward(); break;
            case 9: list.reverse(); break;
            case 10: list.getLength(); break;
            case 0: exit(0);
            default: cout << "Invalid choice.\n";
        }
    }

    return 0;
}
