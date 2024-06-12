#include <iostream>

using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int value){
            this->value = value;
            next = nullptr;
        }
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
        int length;
    public:
        LinkedList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }
        ~LinkedList(){
            Node* temp = head;
            while(head){
                head = head->next;
                cout << "deleted node with value: " << temp->value << endl;
                delete temp;
                temp = head;
                
            }
        }

void print(){
    Node* temp = head;
    while(temp){
        cout << temp->value << endl;
        temp = temp->next;
    }
}

void getHead(){
    cout << "Head is " << head->value << endl;
}

void getTail(){
    cout << "Tail is " << tail->value<< endl;
}

void getLength(){
    cout << "Length is " << length << endl;
}

void append(int value){
    Node* newNode = new Node(value);
    if(length == 0){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

void deleteLast(){
    Node* n = head;
    Node* temp = head;
    if(length == 0){
       return;
    }
        while(n->next != nullptr){
            temp = n;
            n = n->next;
        }
        tail = temp;
        tail->next = nullptr;
        length--;
    if(length == 0){
        head = nullptr;
        tail = nullptr;
    }
        delete n;
}
void prepend(int value){
    Node* newNode = new Node(value);
    if( length == 0){
        head = newNode;
        tail = newNode;
    }
    else{
    newNode->next = head;
    head = newNode;
    }
    length++;
}
void deleteFirst(){
    Node* n = head;
    if(length == 0)
    return;
    else if( length == 1){
        head = nullptr;
        tail = nullptr;
    }
    else{
        head = head->next;
    }
    delete n;
    length--;
}
Node* get(int index){
    if( index < 0 || index >=length) return nullptr;
    Node* temp = head;
    for(int i = 0; i < index; ++i){
        temp = temp->next;
    }
    return temp;
}
bool set(int index, int value){
   Node* temp = get(index);
   if(temp){
    temp->value = value;
    return true;
   }
   return false;
}

void insert(int index, int value){
    if(index <0 || index >= length) return;
    Node* newNode = new Node(value);
    Node* n = get(index-1);
    if(index == 0)
        prepend(value);
    else if(index == length)
        append(value);
    else{
       newNode->next = n->next;
        n->next = newNode;
    }
    length++;
}

void deleteIndex(int index){
    Node* n = get(index);
    Node* prev = head;
    Node* post = head;
    if(index == 0)
        deleteFirst();
    else if(index == length-1)
        deleteLast();
    else{
        while( prev->next != n)
            prev = prev->next;
        while(n->next != post)
            post = post->next;
            prev->next = post;
         n->next = nullptr;

    }
    delete n;
    length--;
}

// void reverse(){
//      Node* temp = head;
//      head = tail;
//      tail = temp;
//      //tail je sada fakticki head, a head je tail
//      Node* post = temp;
//      Node* prev = nullptr;
//      for(int i = 0; i<length; i++){
//         post = temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp = post; 
//      }

// }
// };

void reverse(){
    Node* prev = nullptr;
    while( head != nullptr ) {
        Node* forward = head->next;
        head->next = prev;
        prev = head;
        head = forward; 
    }
    head = prev;
}
};

int main(){
    LinkedList* myLinekedList = new LinkedList(1);
    myLinekedList->prepend(2);
    myLinekedList->prepend(3);
    myLinekedList->prepend(4);
    myLinekedList->prepend(5);
    myLinekedList->prepend(6);
    myLinekedList->prepend(7);
    myLinekedList->prepend(8);
    myLinekedList->insert(2,23);
    myLinekedList->getHead();
    myLinekedList->reverse();
    myLinekedList->getHead();
    myLinekedList->print();
    myLinekedList->getLength();
    //myLinekedList->set(1,2);
    //cout << myLinekedList->get(2)->value << endl;
    //myLinekedList->deleteIndex(2);
    //myLinekedList->print();
    //myLinekedList->getLength();
    ////myLinekedList->reverse();
    //myLinekedList->print();
}
