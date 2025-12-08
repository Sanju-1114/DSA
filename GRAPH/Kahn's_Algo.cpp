// topological sort using BFS
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <stack>
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
    
    // dfs approach
    void topologicalSortHelper(int src, vector<bool> &vis, stack<int> &s) {
        vis[src] = true;

        list<int> neighbors = l[src];
        for(int v : neighbors) {
            if(!vis[v]) {
                topologicalSortHelper(v, vis, s);
            }
        }

        s.push(src);
    }

    void topologicalSort() {   // TC: O(V+E)   SC: O(n)
        vector<bool> vis(V, false);
        stack<int> s;

        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                topologicalSortHelper(i,vis,s);
            }
        }

        // print topological order
        while(!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }

        cout << endl;
    }

    void calcIndegree(vector<int> &indeg) {
        for(int u=0; u<V; u++) {
            list<int> neighbors = l[u]; 
            for(int v : neighbors) { // u------>v
                indeg[v]++;
            }
        }
    }

    void topoSort2() { // Kahn's algorithm
        vector<int> indeg(V, 0);
        calcIndegree(indeg);
        queue<int> q;

        // 0 indegree nodes --> starting point 
        for(int i=0; i<V; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while(q.size() > 0) {
            int curr = q.front();
            q.pop();
            cout << curr << " "; 

            list<int> neighbors = l[curr];
            for(int v : neighbors) {
                indeg[v]--;
                if(indeg[v] == 0) { // np pending dependencies
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

};


// for a directed acyclic graph 
int main() {
    Graph graph(6, false);

    graph.addEdge(2, 3);
    graph.addEdge(3, 1);

    graph.addEdge(4, 0);
    graph.addEdge(4, 1);

    graph.addEdge(5, 0);
    graph.addEdge(5, 2);
    
    graph.topoSort2();
    
    return 0;
}