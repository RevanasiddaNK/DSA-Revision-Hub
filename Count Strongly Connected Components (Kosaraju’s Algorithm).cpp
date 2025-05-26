class Solution {
  public:
  
    void dfs(int node,vector<bool>&vis, vector<vector<int>>&adj, stack<int>&st ){
        
        vis[node] = 1;
        for(int nbr : adj[node] ){
            if(!vis[nbr]){
                dfs(nbr, vis, adj, st);
            }
        }
        // Topological Order
        st.push(node);
    }
    
    void dfsRev(int node, vector<bool>&vis, vector<vector<int>>&adj){
        
        vis[node] = 1;
        for(int nbr : adj[node] ){
            if(!vis[nbr]){
                dfsRev(nbr, vis, adj);
            }
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<bool>vis(V,false);
        stack<int>st;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        vector<vector<int>>adjRev(V);
        for(int i=0; i<V; i++){
            vis[i] = false;
            for(int j : adj[i]){
                adjRev[j].push_back(i);
            }
        }
        
        
        int count = 0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            
            if(!vis[top]){
                count++;
                dfsRev(top, vis, adjRev);
            }
        }
        return count;
    }
};
