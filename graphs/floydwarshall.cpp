#include<iostream>
#include<climits>

using namespace std;
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--) {
	    
	    int V;
	    cin >> V;
	    
	    int arr[V][V];
	    int dist[V][V];

	    for(int i = 0; i < V; i++) {
	        for(int j = 0; j < V; j++) {
	            cin >> arr[i][j];
	        }
	    }
	    
	    for(int i = 0; i < V; i++) {
	        for(int j = 0; j < V; j++) {
	            dist[i][j] = arr[i][j];
	        }
	    }
	    
	    for(int k = 0; k < V; k++) {
	        for(int i = 0; i < V; i++) {
	            for(int j = 0; j < V; j++) {
	                if(dist[i][j] > dist[i][k] + dist[k][j])
	                    dist[i][j] = dist[i][k] + dist[k][j];
	            }
	        }
	    }
	    
	    for(int i = 0; i < V; i++) {
	        for(int j = 0; j < V; j++)  {
	            if(dist[i][j] >= 10000000)
	                cout << "INF" << " ";
	            else
                    cout << dist[i][j] <<" ";  
	        }
	        cout << endl;
	    }
	    
	}
	
	return 0;
}