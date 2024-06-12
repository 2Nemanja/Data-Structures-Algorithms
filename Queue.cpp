#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node* next;

    Node(int value) {
        this->value = value;
        next = nullptr;
    }
    
};

class Queue
{
private:
    Node* first;
    Node* last;
    int length;

public:
    Queue(int value) {
        Node* newNode = new Node(value);
        first = newNode;
        last = newNode;
        length = 1;
    }

    void print(){
        Node* n = first;
        while(n) {
            cout << "   " << n->value ;
            n = n->next; 
        }
        cout << " " << endl;
    }
    
    void getFirst() {
        if(first)
        cout << "First: " << first->value << endl;
        else
        cout << "First: " << NULL << endl;
    }
    void getLast() {
         if(last)
        cout << "Last: " << last->value << endl;
        else
        cout << "last: " << NULL << endl;
    }
    void getLength() {
         if( length != 0 )
        cout << "Length: " << length << endl;
        else
        cout << "Length: " << NULL << endl;
    }

    void add( int value ) {
        Node* newNode = new Node(value);
        if( length == 0 ) {
                first = newNode;
                last = newNode;
        } else {
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    int remove() {
        if( length == 0 ) {
            return INT16_MIN;
        }
        Node* n = first;
        int removed = first->value;
        if( length == 1 ) {
            first = nullptr;
            last = nullptr;
        
        }else {
            first = first->next;
        }
        delete n;
        length--;
        return removed;
    }
};

int main(){

    Queue* my = new Queue(23);
    my->add(2323);
    my->add(232323);
    my->print();
    cout << "youve just removed: " << my->remove() << endl;
    cout << "youve just removed: " << my->remove() << endl;
    cout << "youve just removed: " << my->remove() << endl;
    cout << "youve just removed: " << my->remove() << endl;
    my->print();
    my->getFirst();
    my->getLast();
    my->getLength();
}


