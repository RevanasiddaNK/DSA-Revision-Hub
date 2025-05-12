class Solution {
  public:
    
    vector<int> topologicalSort(int V, vector<int> indeg, unordered_map<int, vector<int>>& adjList) {
        
        vector<int>topologicalVect;
        queue<int> q;
        int count = 0;
    
        for (int i = 0; i < V; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
    
        while (!q.empty()) {
            int f = q.front();
            q.pop();
    
            topologicalVect.push_back(f);
            
            for (int nbr : adjList[f]) {
                indeg[nbr]--;
                if (indeg[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        return topologicalVect;
       
    }
    
    void dfs(int node, unordered_map<int, vector<int>>&adjList, vector<int>&vis,vector<int>&ans ){
        
        vis[node] = true;
        
        for(int i : adjList[node]){
            if(!vis[i]){
                dfs(i, adjList, vis, ans );
            }
        }
        ans.push_back(node);
    }
  
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>>adjList;
        vector<int>indeg(V,0);
        int n = edges.size();
        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            indeg[v]++;
            
            adjList[u].push_back(v);
        }
        
        //return topologicalSort(V, indeg, adjList);
        
        vector<int>ans;
        vector<int>vis(V+1, 0);
        dfs(0, adjList, vis, ans );
        for(int node=0; node<V; node++){
            if(!vis[node]){
                dfs(node, adjList, vis, ans );
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
