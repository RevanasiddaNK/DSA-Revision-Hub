class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<bool>vis(n,0);
        vector<int>bfs;
        queue<int>q;
         vis[0] = 1;
        q.push(0);
        while(!q.empty()){
            int f= q.front();
            bfs.push_back(f);
            q.pop();
            for(int node : adj[f]){
                if(!vis[node]){
                    q.push(node);
                     vis[node] = 1;
                }
            }
        }
        return bfs;
    }
};
