#include<iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;

class Graph {

    list<int> *adj;
    int vertex;

    public:

    Graph(int V);
    void addEdge(int start, int dest);
    void dfsUtil(int v, bool visited[]);
    int motherVertex();
};

Graph::Graph(int V) {
    vertex = V;
    adj = new list<int>[vertex];
}

void Graph::addEdge(int start, int dest) {
    adj[start].push_back(dest);
}

void Graph::dfsUtil(int v, bool visited[]) {

    visited[v] = true;
    for(auto &it : adj[v]) {
        if(!visited[it])
            dfsUtil(it, visited);
    }
}

int Graph::motherVertex() {

    bool visited[vertex];
    vector<int> ans;

    for(int i = 0; i < vertex; i++)
        visited[i] = false;

    int last_finished;
    for(int i = 0; i < vertex; i++) {
        if(!visited[i]) {
            dfsUtil(i, visited);
            last_finished = i;
        }
    }

    for(int i = 0; i < vertex; i++)
        visited[i] = false;
    
    dfsUtil(last_finished, visited);
    for(int i = 0; i < vertex; i++) {
        if(!visited[i])
            return -1;
    }

    return last_finished;

    
}

int main() {

    Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 

    int res;
    res = g.motherVertex();

    cout << res << endl;
    
    return 0;
}

/* An alternative solution would be to count the
 indegree of all the vertices of a graph. 
 All the vertex with zero in degree would be the mother vertex. */
