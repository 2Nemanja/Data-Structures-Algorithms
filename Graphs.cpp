#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph {
    private:
    //ova linija koda daje unordered mapu sa elementima ciji ce kljuc biti prvi parametar(string), a "value" ce biti (unordered_set<string>)
        unordered_map<string, unordered_set<string>> adjList;

        public:

   void print() {
    for( auto [vertex, edges] : adjList ) {
        cout << vertex << " : [ ";
        for( auto edge : edges ) {
            cout << edge << ", ";
        }
        cout << "]" << endl; 
    }
   }
        bool addVertex(string vertex) {
            if(adjList.count(vertex) == 0) {
                adjList[vertex];
                //ovaj deo koda ubacuje vertex u mapu, bez value tj bez njegovih edge-ova
                return true;
            } else {
                return false;
            }
        }

        bool addEdge(string vertex1, string vertex2) {
            if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0) {
                adjList.at(vertex1).insert(vertex2);
                adjList.at(vertex2).insert(vertex1);
                return true;
            }
            return false;
        }

        void removeEdge(string vertex1, string vertex2) {
           if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0 ) {
                adjList.at(vertex1).erase(vertex2);
                adjList.at(vertex2).erase(vertex1);
           }
        }

        bool removeVertex( string vertex ) {
            if( adjList.count(vertex) != 0 ) {
                for( auto edzovi : adjList.at(vertex) ) {
                    adjList.at(edzovi).erase(vertex);
                }
                adjList.erase(vertex);
                return true;
            }
            return false;
        }
};

int main() {
    Graph* my = new Graph();
    my->addVertex("N");
    my->addVertex("T");
    my->addVertex("C");
    my->addVertex("P");

    my->addEdge("N", "T");

    my->addEdge("T", "C");
    my->addEdge("T", "P");
    my->addEdge("N", "P");
    my->addEdge("C", "P");
    cout << "Dodavanje edge-a: " << my->addEdge("N", "g") << endl;
    cout << "Brisanje vertex-a: " << my->removeVertex("P") << endl;
    my->print();
    //my->removeEdge("N" , "C");
    //my->removeEdge("N" , "T");
    //my->print();
}