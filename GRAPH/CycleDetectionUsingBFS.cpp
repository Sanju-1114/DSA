#include <iostream>
#include <vector>
#include <list>
#include <queue>
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

    bool undirectedCycleHelper(int src, vector<bool> &visited){   // O(V+E)
        queue<pair<int, int>> Q;  // node, par

        Q.push({src, -1});
        visited[src] = true;

        while(Q.size() > 0) {
            int u = Q.front().first;
            int par = Q.front().second;
            Q.pop();

            list<int> neighbors = l[u];

            for(int v : neighbors) {
                if(!visited[v]) {
                    Q.push({v, u});
                    visited[v] = true;
                } else if(v != par) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycleUndir() {
        vector<bool> vis(V, false);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(undirectedCycleHelper(i, vis)) {
                    return true;
                }
            }
        }

        return false;
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