class Solution {
  public:
  
    void dfsTraversal(int node,int parent, vector<int>&dfsvect, vector<bool>&vis,vector<vector<int>>& adj ){
        
        dfsvect.push_back(node);
        vis[node] = 1;
        for(int i : adj[node]){
           if(!vis[i]){
                dfsTraversal(i, dfsvect, vis, adj);
            }else if(i != parent){
                return
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
    
        int n = adj.size();
        vector<int>dfsvect;
        vector<bool>vis(n,0);
        for(int node=0; node<n; node++){
            if(!vis[node]){
                dfsTraversal(node,-1, dfsvect, vis, adj);
            }
        }
        return dfsvect;
    }
};
