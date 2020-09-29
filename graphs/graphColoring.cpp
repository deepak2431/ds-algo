   
   Leetcode 1042
   
   vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        
        list<int> *adj;
        vector<int> color(N, -1);
        vector<bool> color_used(4, false);
        
        adj = new list<int> [N];
        
        for(const auto& edge: paths) {
            adj[edge[0] - 1].emplace_back(edge[1] - 1);
            adj[edge[1] - 1].emplace_back(edge[0] - 1);
        }
        
        for(int i = 0; i < N; i++) {
            
            for(auto &it : adj[i]) {
                if(color[it] != -1) {
                    color_used[color[it] - 1] = true;
                }
            }
            
            for(int cr = 0; cr < 4; cr++) {
                if(color_used[cr] == false) {
                    color[i] = cr+1;
                    break;
                }
            }
            
            for(auto &it : adj[i]) {
                if(color[it] != -1) {
                    color_used[color[it] - 1] = false;
                }
            }
        }
        
        return color;