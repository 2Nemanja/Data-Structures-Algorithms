#include <iostream>
using namespace std;

class Node {
    public:
        int value;
        Node* left;
        Node* right;

        Node(int value) {
            this->value = value;
            left = nullptr;
            right = nullptr;
        }
};

class BinarySearchTree {
    public:
        Node* root;

        BinarySearchTree() {
            root = nullptr;
        }
        bool insert(int value) {
        Node* newNode = new Node(value);
        if( root == nullptr ) {
            root = newNode;
            return true;
        }
        Node* n = root;
        while( true ) { //beskonacna petlja, jedini izlaz je preko return-a
            if( newNode->value == n->value )    return false;
            
            if( newNode->value < n->value ) {
                if( n->left == nullptr ){
                    n->left = newNode;
                    return true;
                }
                n = n->left;
            } else {
                if( n->right == nullptr ) {
                    n->right = newNode;
                    return true;
                }
                n = n->right;
            }
        }
    }

    bool contains(int value) {
        if( root == nullptr )   return false;

        Node* n = root;
        while ( n ) {
        if( value == n->value )  return true;
        else if(value < n->value) {
                n = n->left;  
            } else {
                n = n->right;
            }
        }
        return false;
    }
};

int main() {
    BinarySearchTree* my = new BinarySearchTree();
    
    my->insert(47);
    my->insert(21);
    my->insert(76);
    my->insert(18);
    my->insert(52);
    my->insert(82);

    my->insert(27);
    cout << "Element koji se trazi je u listi? " << my->contains(23) << endl;
    cout << my->root->left->right->value << endl;
}
