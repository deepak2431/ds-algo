#include<iostream>
#include<climits>
#define V 9

using namespace std;

int minIndex(int dist[], bool mstSet[]) {

    int min_index, min = INT_MAX;
    for(int i = 0; i < V ; i++) {
        if(!mstSet[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;

}

void printSoln(int dist[]) {
    for(int i = 0; i < V; i++) {
        cout << i << " " << dist[i] << endl;
    }
}

void dijkstraAlgo(int graph [V][V], int src) {

    bool mstSet[V];
    int dist[V];
    
    for(int i = 0; i < V; i++) {
        mstSet[i] = false;
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for(int count = 0; count < V-1; count++) {

        int u = minIndex(dist, mstSet);
        mstSet[u] = true;
        for(int v = 0; v < V; v++) {
            if(graph[u][v] && !mstSet[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSoln(dist);
}

int main() 
{ 
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 }, 
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 }, 
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 }, 
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 }, 
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 }, 
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 }, 
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 }, 
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 }, 
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } }; 
  
    dijkstraAlgo(graph, 0); 
  
    return 0; 
} 