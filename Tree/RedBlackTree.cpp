#include<iostream>
using namespace std;

enum Color {RED, BLACK};

struct node{
    int data;
    bool color;
    node *left, *right, *parent;

    node(int data){
        this->data = data;
        left = right = parent = nullptr;
        color = RED;
    }
};

class RBTree{
    private:
        node *root;

        void rotateLeft(node *&root, node *&x){
            node *y = x->right;
            x->right = y->left;

            if(y->left != nullptr){
                y->left->parent = x;
            }
            y->parent = x->parent;

            if(x->parent == nullptr){
                root = y;
            }
            else if(x == x->parent->left){
                x->parent->left = y; 
            }
            else{
                x->parent->right = y;
            }

            y->left = x;
            x->parent = y;
        }

        void rotateRight(node *&root, node *&x){
            node *y = x->left;
            x->left = y->right;

            if(y->right != nullptr){
                y->right->parent = x;
            }

            y->parent = x->parent;

            if(x->parent == nullptr){
                root = y;
            }
            else if(x == x->parent->right){
                x->parent->right = y;
            }
            else{
                x->parent->left = y;
            }
            y->right = x;
            x->parent = y;
        }

        void fixViolation(node *&root, node *&pt){
            node *parent = nullptr;
            node *grandparent = nullptr;

            while(pt != root && pt->color == RED && pt->parent->color == RED){
                parent = pt->parent;
                grandparent = parent->parent;

                if(parent == grandparent->left){
                    node *uncle = grandparent->right;

                    if(uncle != nullptr && uncle->color == RED){
                        grandparent->color = RED;
                        parent->color = uncle->color = BLACK;
                        pt = grandparent;
                    }
                    else{
                        if(pt == parent->right){
                            rotateLeft(root, parent);
                            pt = parent;
                            parent = pt->parent;
                        }

                        rotateRight(root, grandparent);
                        swap(parent->color, grandparent->color);
                        pt = parent;
                    }
                }
                else{
                    node *uncle = grandparent->left;
                    if(uncle != nullptr && uncle->color == RED){
                        grandparent->color = RED;
                        parent->color = uncle->color = BLACK;
                        pt = grandparent;
                    }
                    else{
                        if(pt == parent->left){
                            rotateRight(root, parent);
                            pt = parent;
                            parent = pt->parent;
                        }
                        rotateLeft(root, grandparent);
                        swap(parent->color, grandparent->color);
                        pt = parent;
                    }
                }
            }
            root->color = BLACK;
        }

    public:
        RBTree(){root = nullptr;}
        
        void insert(int data){
            node *pt = new node(data);
            node *parent = nullptr;
            node *current = root;

            while(current != nullptr){
                parent = current;
                if(pt->data < current->data){
                    current = current->left;
                }
                else if(pt->data > current->data){
                    current = current->right;
                }
                else return;
            }

            pt->parent = parent;

            if(parent == nullptr){
                root = pt;
            }
            else if(pt->data < parent->data){
                parent->left = pt;
            }
            else{
                parent->right = pt;
            }

            fixViolation(root, pt);
        }

        void inorder(node *root){
            if(root == nullptr) return;
            inorder(root->left);
            cout<<root->data<<"("<<(root->color == RED ? "R" : "B") <<") ";
            inorder(root->right);
        }

        void display(){
            cout<<"Inorder Traversal: ";
            inorder(root);
            cout<<endl;
        }

};

int main(){
    RBTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);

    tree.display();

    return 0;
}