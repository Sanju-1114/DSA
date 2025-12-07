#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v) { // u-----v
        l[u].push_back(v);
        l[v].push_back(u);
    }
    
    void bfsHelper(int i, vector<bool> &vis) { // O(V + E)
        queue<int> q;
        q.push(i);
        vis[i] = true;

        while(q.size() > 0) {
            int u = q.front(); // curr vertex
            q.pop();
            cout << u << " ";

            list<int> neighbors = l[u]; // u-----v
            for(int v : neighbors) {
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    void bfs() {
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                bfsHelper(i, vis);
                cout << endl;
            }
        }
    }

    void dfsHelper(int u, vector<bool> &vis) { // O(v + E)
        cout << u << " ";
        vis[u] = true;
        list<int> neighbors = l[u];

        for(int v : neighbors) {
            if(!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs() {
        vector<bool> vis(V, false);
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfsHelper(i, vis); // starting point = i
                cout << endl;
            }
        }
        cout << endl;
    }
};

int main() {
    Graph graph(10);

    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 3);
    graph.addEdge(4, 9);
    graph.addEdge(3, 7);
    graph.addEdge(3, 8);

    graph.addEdge(2, 0);
    graph.addEdge(2, 5);

    // graph.dfs();
    graph.bfs();
    
    return 0;
}