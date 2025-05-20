class Solution {
  public:
    
    int findMinKeyIndex(int V, vector<int>&key, vector<bool>&mst){
        
        int min = INT_MAX, minIndex = -1;
        for(int i=0; i<V; i++){
            
            if( !mst[i] && key[i] < min){
                min = key[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
    
    int spanningTree1(int V, vector<vector<int>> adj[]) {
        
        vector<int>key(V,INT_MAX);
        vector<bool>mst(V,false); 
        vector<int>parent(V, -1);
        
        key[0] = 0;
        parent[0] = -1;
        
        for(int node=0; node<V; node++){
    
            int u = findMinKeyIndex(V, key, mst);
            mst[u] = 1;
            
            for( auto &nbr : adj[u] ){
                int v = nbr[0];
                int w = nbr[1];
                if( !mst[v] && w  < key[v] ){
                    key[v] = w;
                }
            }
        }
        
        int wt = 0;
        for(int node=0; node<V; node++){
            wt += key[node];
        }
        return wt;
    }
    
    int spanningTree(int V, vector<vector<int>> adj[]){
        
        //return spanningTree1(V, adj);
        
        int wt = 0;
        priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
        pq.push({0,0});
        
        vector<bool>vis(V,0);
        
        while(!pq.empty()){
            
            auto node = pq.top();
            int w = node.first;
            int u = node.second;
            
            pq.pop();
            
            if(vis[u]){
                continue;
            }
            
            wt += w;
            vis[u] = 1;
            
            for(auto nbr : adj[u] ){
                int v = nbr[0];
                int wv = nbr[1];
                pq.push({wv,v});
            }
        }
        return wt;
    }
    
};
