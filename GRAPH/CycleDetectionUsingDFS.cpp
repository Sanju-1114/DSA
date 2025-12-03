#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int> *l; // int *arr 

public:
    Graph(int V){
        this->V = V;
        l = new list<int> [V];
        // arr = new int[V]
    }    

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool undirectedCycleHelper(int src, int par, vector<bool> &vis){
        vis[src] = true;
        list<int> neighbors = l[src];

        for(int v : neighbors) {
            if(!vis[v]) {
                if(undirectedCycleHelper(v, src, vis)) {
                    return true;
                }
            } else {
                if(v != par) {
                    return true;
                }
            }
        }
    }

    bool isCycleUndir() {
        vector<bool> vis(V, false);
        return undirectedCycleHelper(0, -1, vis);
    }
  
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);

    cout << g.isCycleUndir() << endl;
    
    return 0;
}