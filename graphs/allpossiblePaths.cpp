// To find the all possible paths from source to destination
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>> &g, vector<vector<int>> &res, vector<int> &path, int cur){
    path.push_back(cur);
    if (cur == g.size() - 1)
        res.push_back(path);
    else
        for (auto it : g[cur]) {
             dfs(g, res, path, it);
        }    
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &g){
    vector<vector<int>> paths;
    vector<int> path;
    dfs(g, paths, path, 0);
    return paths;
}

int main() {

    vector<vector<int>> g { { 1, 2 }, 
                         { 3 }, 
                         { 3}, { } };
    vector<vector<int>> res = allPathsSourceTarget(g);

    for(int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
    }

    cout << endl;



}
