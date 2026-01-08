#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float gpa;
    Student* left;
    Student* right;
    int height;
};

int getHeight(Student* node) {
    return node ? node->height : 0;
}

int getBalance(Student* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

Student* createNode(int id, string name, float gpa) {
    Student* newNode = new Student{id, name, gpa, nullptr, nullptr, 1};
    return newNode;
}

// Right rotate
Student* rightRotate(Student* y) {
    Student* x = y->left;
    Student* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

// Left rotate
Student* leftRotate(Student* x) {
    Student* y = x->right;
    Student* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

// Insert
Student* insert(Student* node, int id, string name, float gpa) {
    if (node == nullptr)
        return createNode(id, name, gpa);

    if (id < node->id)
        node->left = insert(node->left, id, name, gpa);
    else if (id > node->id)
        node->right = insert(node->right, id, name, gpa);
    else
        return node; // Duplicate ID not allowed

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalance(node);

    // LL
    if (balance > 1 && id < node->left->id)
        return rightRotate(node);

    // RR
    if (balance < -1 && id > node->right->id)
        return leftRotate(node);

    // LR
    if (balance > 1 && id > node->left->id) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // RL
    if (balance < -1 && id < node->right->id) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// In-order Traversal
void inOrder(Student* root) {
    if (root) {
        inOrder(root->left);
        cout << "ID: " << root->id << ", Name: " << root->name << ", GPA: " << root->gpa << endl;
        inOrder(root->right);
    }
}

int main() {
    Student* root = nullptr;
    root = insert(root, 102, "Sohag", 3.75);
    root = insert(root, 101, "Riya", 3.90);
    root = insert(root, 103, "Imran", 3.60);
    root = insert(root, 100, "Tanvir", 3.50);

    cout << "In-order Traversal of AVL Tree:\n";
    inOrder(root);

    return 0;
}
