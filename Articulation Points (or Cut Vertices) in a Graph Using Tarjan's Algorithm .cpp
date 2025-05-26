class Solution {
  public:
  
  
    void dfs(int node, vector<int>&vis, int parent, int &timer, vector<int>&discTime, vector<int>&lowestTime, vector<bool>&isArticulation,  unordered_map<int, vector<int>>&adjList){
        
        vis[node] = true;
        discTime[node] = lowestTime[node] = timer++;
        int children=0;
        for(int nbr : adjList[node]){
            
            if(nbr == parent)
                continue;
                
            
            if( !vis[nbr] ){
                children++;    
                dfs(nbr, vis,node,timer,discTime,lowestTime,isArticulation,adjList );
                lowestTime[node] = min(lowestTime[node], lowestTime[nbr]);
                
                if(lowestTime[nbr] >= discTime[node] &&  parent != -1){
                    isArticulation[node] = 1;
                }
            }
            else{
                //Backedge which forms cycle in G
                lowestTime[node] = min(lowestTime[node], discTime[nbr]);
            } 
        }
        
        if(parent == -1 && children > 1){
            isArticulation[node] = 1;
        }
        
    }
  
  
    vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>>adjList;
        
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        
        vector<int>vis(V, 0);
        
        int parent = -1;
        int timer = 0;
        vector<int>discTime(V, -1);
        vector<int>lowestTime(V, -1);
        vector<int>articulationPoints;
        vector<bool>isArticulation(V, false);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, vis,parent,timer,discTime,lowestTime,isArticulation,adjList  );
            }
        }
        
        for(int i=0; i<V; i++){
            if(isArticulation[i]){
                articulationPoints.push_back(i);
            }
        }
        return articulationPoints.empty() ?  vector<int>({-1}) : articulationPoints;

    }
};
