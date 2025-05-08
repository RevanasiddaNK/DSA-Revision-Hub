class Solution {
  public:
  
    bool dfs(int node, vector<bool>&vis, vector<bool>&dfsVis,  unordered_map<int, vector<int>>&adjList){
        
        vis[node] = 1;
        dfsVis[node] = 1;
        
        for(int nbr : adjList[node]){
            if(!vis[nbr]){
                bool haveCycle = dfs(nbr, vis,dfsVis, adjList);
                if(haveCycle)
                    return 1;
            }else if(dfsVis[nbr]){
                return 1;
            }
        }
        dfsVis[node] = 0;
        return 0;
    }
    
    bool topologicalSort(int V, vector<int> indeg, unordered_map<int, vector<int>>& adjList) {
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
            count++;  // count how many nodes we've processed
    
            for (int nbr : adjList[f]) {
                indeg[nbr]--;
                if (indeg[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    
        // If count != V, there is a cycle (some nodes couldn't be processed)
        return count != V;
    }

  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        unordered_map<int, vector<int>>adjList;
        vector<int>indeg(V,0);
        int n = edges.size();
        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            
            indeg[v]++;
            
            adjList[u].push_back(v);
        }
        
        return topologicalSort(V, indeg, adjList);
        /*
        vector<bool>vis(V,0);
        vector<bool>dfsVis(V,0);
        for(int node=0; node<V; node++){
            
            if(!vis[node]){
                bool haveCycle = dfs(node, vis, dfsVis ,adjList);
                if(haveCycle)
                    return 1;
            }
        }
        return 0;
        */
    }
};
