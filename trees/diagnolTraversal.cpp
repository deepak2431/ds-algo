 void diagnolTraversalUtil(TreeNode *root, int d, map<int, vector<int>> &ans) {
     
     if(!root)
        return;
    ans[d].push_back(root->val);
    diagnolTraversalUtil(root->left, d+1, ans);
    diagnolTraversalUtil(root->right, d, ans);
     
 }
vector<int> Solution::solve(TreeNode* A) {
    
    map<int, vector<int>> ans;
    diagnolTraversalUtil(A, 0, ans);
    
    vector<int>traversal;
    
    for(auto &it : ans) {
        for(auto &node : it.second)
            traversal.push_back(node);
    }
    return traversal;
    
}