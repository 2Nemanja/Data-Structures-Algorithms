#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;
        Node* prev;
            Node(int value){
                this->value = value;
                next = nullptr;
                prev = nullptr;
            }
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        DoublyLinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
    
    void print(){
        Node* temp = head;
        while(temp){
            cout << temp->value << endl;
            temp = temp->next;
        }
    }

    void getHead(){
        if( head ) {
            cout << "head is: " << head->value << endl;
        } else {
            cout << "head is: " << NULL << endl;
        }
        
    }

    void getTail(){
        if( tail ) {
            cout << "tail is: " << tail->value << endl;
        } else {
            cout << "tail is: " << NULL << endl;
        }
    }
    void getLength(){
        cout << "length is: " << length << endl;
    }

    void append(int value){
        Node* newNode = new Node(value);
        if(length == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    void deleteLast() {
        if(length == 0) return;
        Node* temp = tail;
        if(length == 1){
            head = nullptr;
            tail = nullptr;
        }
        else{
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepend(int value){
        Node* newNode = new Node(value);
        if(length == 0){
            head = newNode;
            tail = newNode;
        }
        else{
            head->prev    = newNode;
            newNode->next = head;
            head          = head->prev;
        }
        length++;
    }

    void deleteFirst() {
        Node* newNode = head;
        if( length == 0 ) {
            delete newNode;
            return;
        } else if( length == 1 ) {
            head = nullptr;
            tail = nullptr;
        } else { 
            head = head->next;
            head->prev = nullptr; 
        }
        
        delete newNode;
        length--;
    }
    Node* get( int index ) {
        if( index < 0 || index > length ) return nullptr;
        Node* n = head;
        if( index < length/2 ){
            for( int i = 0 ; i < index ; i++ ) {
                n = n->next;
                 }
            }
        else{
            n = tail;
            for(int i = length-1 ; i > index ; i--){
                n = n->prev;
            }
        }
        return n;
    }
/*
        KOD KOJI SAM JA PISAO, ISPOD JE EFIKASNIJE URADJENO

    void set(int index, int value) {
        if( length == 0 )
            append(value);
        Node* n = head;
        if( index < length/2 ){
          for( int i = 0; i < index; i++ ) {
               n = n->next;
             }
        }else{
            n = tail;
            for( int i = length - 1; i > index; i-- ) {
                n = n->prev;
            }
        }
        n->value = value;
    }
*/

bool set(int index, int value) {
    Node* n = get(index);
    if( n ) {
        n->value = value;
        return true;
    }
    return false;
}

bool insert( int index, int value ) {
    if( index < 0 || index > length ){
        return false;
    }
        if( index == 0 ) {
            prepend(value);
            return true;
            }
        if( index == length ){
            append(value);
            return true;
        }

    Node* newNode = new Node(value);
    Node* n = get(index - 1);
    Node* m = n->next;
    newNode->prev = n;
    newNode->next = m;
    n->next = newNode;
    m->prev = newNode;
    length++;
}

void deleteIndex(int index) {
    if( index < 0 || index > length ){
        return;
    }
    if( index == 0 ) {
        deleteFirst();
    }
    if( index == length-1 ){
        deleteLast();
    }
    Node* n = get(index);
    n->next->prev = n->prev;
    n->prev->next = n->next;
    delete n;
    length--;
}
};

int main(){
    DoublyLinkedList* my = new DoublyLinkedList(1);
    my->append(2);
    my->append(3);
    my->append(4);
    my->append(5);
    my->append(6);
    my->prepend(23);
    my->deleteFirst();
    my->deleteFirst();
    my->deleteFirst();
    my->deleteFirst();
    my->deleteFirst();
    my->deleteFirst();
    my->deleteFirst();
    my->print();
    my->getTail();
    my->append(6);
    my->append(7);
    my->append(23);
    my->append(31);
    my->append(1);
    my->print();
   // my->set(3,23);
    cout << "--------------------" << endl;
    my->insert(2,2323);
    my->print();
    cout << "--------------------" << endl;
    my->deleteIndex(2);
    my->print();
    my->getTail();
    cout << "Vracenja vrednost je: " << my->get(2)->value << endl;
    // my->deleteFirst();
    // my->deleteFirst();
    //my->deleteLast();
    //my->print();
    //my->getHead();
    //my->getLength();

}
