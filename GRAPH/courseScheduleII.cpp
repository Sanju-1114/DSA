#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isCycle(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &graph) {
    vis[src] = true;
    recPath[src] = true;

    for(int i=0; i<graph.size(); i++) {
        int u = graph[i][1];
        int v = graph[i][0];

        if(u == src) {
            if(!vis[v]) {
                if(isCycle(v, vis, recPath, graph)) {
                    return true;
                }
            } else {
                if(recPath[v]) {
                    return true;
                }
            }
        }
    }

    recPath[src] = false;
    return false;

}

void topoSort(int src, vector<bool> &vis, stack<int> &s, vector<vector<int>> &graph) {
    vis[src] = true;

    for(int i=0; i<graph.size(); i++) {
        int u = graph[i][1];
        int v = graph[i][0];

        if(u == src) {
            if(!vis[v]) {
                topoSort(v, vis, s, graph);
            }
        }
    }

    s.push(src);
}

vector<int> findOrder(int numCourses, vector<vector<int>> &graph) {   //O(v+E)
    int V = numCourses;   // [v, u]    v <---- u
    vector<bool> vis(V, false);
    vector<bool> recPath(V, false);
    vector<int> ans;
    for(int i=0; i<V; i++) {
        if(!vis[i]) {
            if(isCycle(i, vis, recPath, graph)) {
                return ans;
            }
        }
    }

    //topological sorting
    vector<bool> vis2(V, false);
    stack<int> s;
    for(int i=0; i<V; i++) {
        if(!vis2[i]) {
            topoSort(i, vis2, s, graph);
        }
    }

    while (!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;

}

int main() {
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};

    for(int i : findOrder(numCourses, prerequisites)) {
        cout << i << " ";
    }
    
    cout <<  endl;

    return 0;
}