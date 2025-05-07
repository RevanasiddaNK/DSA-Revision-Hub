class Solution {
  public:
  
    bool dfs(int node, int parent, vector<bool>&vis, unordered_map<int, vector<int>>&adjList){
        vis[node] = 1;
        for(int i : adjList[node]){
           if(!vis[i]){
                int hvCycle = dfs(i,node, vis, adjList);
                if(hvCycle)
                    return 1;
            }else if(i != parent){
                return 1;
            }
        }
        return 0;
    }
    
    bool bfs(int node, vector<bool>& vis, unordered_map<int, vector<int>>& adjList) {
        queue<pair<int, int>> q; // {current_node, parent_node}
        vis[node] = true;
        q.push({node, -1});
    
        while (!q.empty()) {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();
    
            for (int neighbor : adjList[curr]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push({neighbor, curr});
                } else if (neighbor != parent) {
                    // Visited node that is not the parent => cycle
                    return true;
                }
            }
        }
        return false;
    }

  
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>>adjList;
        vector<bool>vis(V,0);
        
        int n = edges.size();
        for(int i=0; i<n; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
        
        for(int node=0; node<V; node++){
            if(!vis[node]){
                //  int hvCycle = dfs(node, -1, vis, adjList);
                int hvCycle = bfs(node, vis, adjList);
                if(hvCycle)
                    return 1;
            }
        }
        return 0;
    }
};
