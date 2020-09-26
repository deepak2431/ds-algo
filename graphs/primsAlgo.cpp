#include<iostream>
#include<vector>
#include<climits>

#define V 5

using namespace std;

int minKey(int mstSet[], int key[]) {
    int min = INT_MAX, min_index = 0;
    for(int i = 0; i < V; i++) {
        if(!mstSet[i] && key[i] < min)  {
            min_index = i;
            min = key[i];
        }
    }
    return min_index;
}

void printMst(int parent[], int graph[V][V]) 
{ 
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++) 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 

void primMST(int graph[V][V]) {

    int parent[V];
    int mstSet[V];
    int key[V];

    for(int i = 0; i < V; i++) {
        mstSet[i] = 0;
        key[i] = INT_MAX;
    }
    for(int count = 0; count < V-1; count++) {

        int u = minKey(mstSet, key);
        mstSet[u] = 1;
        for(int v = 0; v < V; v++) {
            if(graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }
    printMst(parent, graph);
}

int main() 
{ 
    /* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | / \ | 
    (3)-------(4) 
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 
 
    // Print the solution 
    primMST(graph); 
 
    return 0; 
} 