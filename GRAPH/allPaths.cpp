#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
using namespace std;

class Graph {
    int V;
    list<int>* l;
    bool isUndir;
public:
    Graph(int V, bool isUndir=true) {
        this->V = V;
        l = new list<int> [V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v) { // u-----v  undirected     u---->v directed
        l[u].push_back(v);
        if(isUndir) {
            l[v].push_back(u);
        }
    }
    
    void printAllPathsHelper(int src, int dest, vector<bool> &vis, string &path) { // O(V+E)
        if(src == dest) {
            cout << path << dest << endl;
            return;
        }

        vis[src] = true;
        path += to_string(src);
        list<int> neighbors = l[src];
        
        for(int v : neighbors) {
            if(!vis[v]) {
                printAllPathsHelper(v, dest, vis, path);
            }
        }

        path = path.substr(0, path.size()-1);
        vis[src] = false;
    }

    void printAllPaths(int src, int dest) {
        vector<bool> vis(V, false);
        string path = "";

        printAllPathsHelper(src, dest, vis, path);
    }

};


// print all paths from src to dest for a directed graph 
int main() {
    Graph graph(6, false);

    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);
    
    graph.printAllPaths(5, 1);

    
    return 0;
}