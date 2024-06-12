#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;

    Node( int value ) {
        this->value = value;
        next = nullptr;
    }
};

class Stack {
    private:
        Node* top;
        int height;

    public:
        Stack( int value ){
            Node*  newNode = new Node(value);
            top = newNode;
            height = 1; 
        }

    void print() {
        Node* temp = top;
        while( temp ) {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHeight() {
        cout << "Heigth: " <<  height << endl;
    }

    void getTop() {
        cout << "Top: " << top->value << endl;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop() {
        if( height ==  0 ) {
            return INT16_MIN; //INT MIN se koristi da bismo znali da je stek prazan, jer sa ostalim int vrednostima ne mozemo biti sigurni da
        } else {
        Node* n = top;
        int vrednost = top->value;
        top = top->next;
        delete n;
        height--;
        return vrednost;
        }
    }
};

int main() {
    Stack* my = new Stack(1);
    my->getHeight();
    my->getTop();
    my->push(23);
    cout << "Poped value: " << my->pop() << endl;
    cout << "Poped value: " << my->pop() << endl;
    cout << "Poped value: " << my->pop() << endl;
  


}