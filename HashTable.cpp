#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
        string key;
        int value;
        Node* next = nullptr;

        Node(string key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
};

class HashTable {
    private: 
        static const int SIZE = 7; // static znaci da ce svaka kreirana hes tabele koristiti istu const vrednist 7,
                                  // a const vrednosti bi trebalo imenovati CAPSLOCK
       
       public:
        Node* dataMap [SIZE];
          
           ~HashTable() {
            for(int i = 0; i < SIZE; i++) {
                Node* head = dataMap[i];
                Node* temp = head;
                while (head) {
                    head = head->next;
                    delete temp;
                    temp = head;
                }
            }
        }
          
          void print() {
            for(int i = 0; i < SIZE; i++) {
                cout << i << " : ";
                if(dataMap[i]) {
                    Node* temp = dataMap[i];
                    while (temp) {
                        cout << "   { " << temp->key << ", " << temp->value << " }" << endl;
                        temp = temp->next;
                    }
                }
            }
        }

    int hash(string key) {
        int hash = 0;
        for(int i= 0; i<SIZE; i++) {
            int asciiVal = int(key[i]);
            hash = (hash + asciiVal *23) % SIZE; //23 je random prost broj kako bi output bio sto vise random
                                                // ova hash fja ce vracati samo brojeve od 0-6 jer koristimo %7 
                                               //  koja za sve moguce brojeve vraca samo te cifre
        }
        return hash;
    }
    
    void set( string key, int value ){
        int index = hash(key);
        Node* newNode = new Node(key, value);
        if(dataMap[index] == nullptr) {
            dataMap[index] = newNode;
        } else {
            Node* n = dataMap[index]; // dataMap[index] je ekvivalentno kao = head posto je to prvi pokazivac u bucket-u
            while(n->next != nullptr) {
                n = n->next;
            }
            n->next = newNode;
        }
    }

    int get(string key) {
        int index = hash(key);
        Node* n = dataMap[index];
        while( n ) {
            if(n->key == key) {
                return n->value;
            }
            n = n->next;
        }
        return 0;
    }

vector<string> keys(){
    vector<string> svi;
    for( int i = 0; i < SIZE; i++){
        Node* n = dataMap[i];
        while( n ){
            svi.push_back(n->key);
            n = n->next;
        }
    } return svi;
}
};

int main() {
    HashTable* my = new HashTable();
    my->set("prvi",23);
    my->set("drugi",2);
    my->set("treci",3);
    my->set("cetvrti",5);
    my->set("peti",6);
    my->set("sesti",7);
    my->set("sedmi",8);

    cout << "drugi: " << my->get("drugi") << endl;
    cout << "sesti: " << my->get("sesti") << endl;
    cout << "stoti: " << my->get("stoti") << endl;

    vector<string> myKeys = my->keys();
    for( auto key : myKeys ) {
        cout << key << ", ";
    }
}