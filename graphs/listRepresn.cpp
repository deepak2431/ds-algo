#include<iostream>
#include<vector>

using namespace std;

class Graph {
    
    vector<int> adj[5]; // array of vectors
    int vertex;

    public:

    Graph(int v);
    void addEdge(int startV, int endV);
    void displayGraph();
};

Graph:: Graph(int v) {
    vertex = v;
}

void Graph::addEdge(int startV, int endV) {
    adj[startV].push_back(endV);
    adj[endV].push_back(startV);
}

void Graph::displayGraph() {

    for(int i = 0; i < vertex; i++) {
        cout << "The edges from vertex " << i << " ";
        for(auto &e : adj[i]) {
            cout << e << " ";
        }
        cout << endl;
    }   
}

int main() {

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(3, 2);
    g.addEdge(4,1);

    g.displayGraph();


}