

//function definition of Breadth First Algorithm
vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    bool visited[N];
    
    for(int i = 0; i < N; i++)
        visited[i] = false;
    queue<int> q;
    vector<int> ans;
    q.push(0);
    
    while(!q.empty()) {
        
        int s = q.front();
        ans.push_back(s);
        q.pop();
        
        for(auto &it : g[s]) {
            if(!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }
    }
    return ans; 
}

//Dfs Traversal function

void dfsUtil(vector<int> g[], int v, vector<int> &ans, bool visited[]) {
    
    visited[v] = 1;
    ans.push_back(v);
    
    for(auto &it : g[v]) {
        if(!visited[it])
            dfsUtil(g, it, ans, visited);
    }
    
    
}
vector <int> dfs(vector<int> g[], int N)
{
    
    // Your code here
    bool visited[N];
    for(int i = 0; i < N; i++) {
        visited[i] = false;
    }
    vector<int> ans;
    dfsUtil(g, 0, ans, visited);
    
    return ans;

}