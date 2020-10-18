#include <iostream>
#include<map>
#include<cstring>
#include<list>
using namespace std;

template<typename T>
class Graph{
    map<T, list<T>> adjList;
    public:
        void addEdge(T u,T v,bool bidr = true){
            adjList[u].push_back(v);
            if(bidr){
                adjList[v].push_back(u);
            }
        }
        void printAdjlist(){
            for(auto row : adjList){
                T key = row.first;
                cout<<key<<"->";
                
                for(T element:row.second){
                    cout<<element<<",";
                }
            cout<<endl;
            }
        }
};

int main(){
    Graph<string> g;
    g.addEdge("A","D");
    g.addEdge("A","J");
    g.addEdge("D","S");
    g.addEdge("D","B");
    g.addEdge("D","E");
    g.addEdge("A","S");

    g.printAdjlist();
}
