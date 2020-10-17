#include<iostream>
#include<vector>
#include<climits>

using namespace std;

struct Edge {
    long long  src, dest, weight;

    Edge(long long src, long long dest, long long weight) {
        this->src = src;
        this->dest = dest;
        this->weight = weight;
    }
};

long findDiff(vector<long long> x, vector<long long> y) {

    long diff = 0;
    for(int i = 0; i < x.size(); i++)
        diff += abs(x[i] - y[i]);
    return diff;
}

long long findKey(vector<long long> key, vector<bool> vis, int v) {

    long long max = INT_MIN;
    long long index = -1;
    for(int i = 0; i < v; i++) {
        if(!vis[i] && key[i] > max) {
            max = key[i];
            index = i;
        }
    }

    return index;
}

void printAns(vector<vector<long long>> graph, vector<long long> parent, long long v) {
    
    long long sum = 0;

    for(int i = 1; i < v; i++){

        sum += graph[parent[i]][i];
    }

    cout << sum << endl;
}

void primMst(vector<vector<long long>> graph) {

    long long n = graph.size(), u;
    vector<bool> vis(n, 0);
    vector<long long> parent(n, -1);
    vector<long long> key(n, INT_MIN);

    key[0] = 0;
    parent[0] = -1;

    for(int count = 0; count < n-1; count++) {
        u = findKey(key, vis, n);
        vis[u] = true;
    }
    for(int v = 0; v < n; v++) {
        if(!graph[u][v] && !vis[v] && graph[u][v] > key[v]) {
            parent[v] = u;
            key[v] = graph[u][v];
        }
    
    }

    printAns(graph, parent, n);
}

int main() {

    long long int n, d;
    cin >> n >> d;

    vector<vector<long long >> arr;
    for(int i = 0; i < n; i++) {
        long long num;
        vector<long long> val;
        for(int i = 0; i < d; i++) {
            cin >> num;
            val.push_back(num);
        }
        arr.push_back(val);
    }

    vector<Edge> edges;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i+1; j < n; j++) {
            long long w = findDiff(arr[i], arr[j]);
            Edge curr(i, j, w);
            cout << 0 << endl;
            edges.push_back(curr);
            cout << edges[1].weight << endl;
        }
    }

    vector<vector<long long>> graph(n);
    for(int i = 0; i < edges.size(); i++) {
        cout << edges[i].src << " " << edges[i].dest << " " << edges[i].weight;
        graph[edges[i].src][edges[i].dest] = edges[i].weight;
        graph[edges[i].dest][edges[i].src] = edges[i].weight;
    }

    primMst(graph);


}