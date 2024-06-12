#include <iostream>
#include <queue>
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
class BinaryTree {
    private:
        Node* root;
    public:
        BinaryTree(int value) {
            Node* newNode = new Node(value);
            root = newNode;
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

        void bfs() {
            queue<Node*> myQueue;
            myQueue.push(root);
            while( myQueue.size() > 0 ) {
            Node* current = myQueue.front();
                myQueue.pop();
                cout << current->value << " ";
                if(current->left) {
                    myQueue.push(current->left);
                }
                if(current->right) {
                    myQueue.push(current->right);
                }
            }
        }
            //rekurzivna fja
        void dfsPreorder(Node* current) {
            cout << current->value << " ";
            if(current->left) {
                dfsPreorder(current->left);
            }
            if(current->right) {
                dfsPreorder(current->right);
            }
        }
       void dfsPreorder() {dfsPreorder(root);} //ovom linijom overloadujemo fju da bismo mogli da joj damo root kao parametar
                                              // posto je root private
        void dfsPostorder(Node* current) {
            if(current->left) {
                dfsPostorder(current->left);
            }
            if(current->right) {
                dfsPostorder(current->right);
            }
            cout << current->value << " ";
        }
        void dfsPostorder() {dfsPostorder(root);}

        void dfsInorder(Node* current) {
            if(current->left) {
                dfsInorder(current->left);
            }
            cout << current->value << " ";
            if(current->right) {
                dfsInorder(current->right);
            }
        }
        void dfsInorder() {dfsInorder(root);}
};

int main() {
    BinaryTree* my = new BinaryTree(41);

    my->insert(21);
    my->insert(76);
    my->insert(18);
    my->insert(27);
    my->insert(52);
    my->insert(82);
    my->dfsPreorder();
    cout << "\n\n\n-*-*-*-*-* CALE -*--*-*-*-*\n\n" << endl;
    my->dfsPostorder();
    cout << '\n';
    cout << "\n\n\n-*-*-*-*-* CALE -*--*-*-*-*\n\n" << endl;
    my->dfsInorder();
    cout << '\n';
    
}