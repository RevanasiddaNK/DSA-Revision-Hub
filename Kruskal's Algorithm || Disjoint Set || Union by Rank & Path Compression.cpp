class Solution {
  public:
    
    class DSU {
        
        public:
            vector<int>rank;
            vector<int>parent;
            
        DSU(int V){
            rank.resize(V, 1);
            parent.resize(V);
            for(int i=0; i<V; i++){
                rank[i] = 1;
                parent[i] = i;
            }
        }
        
        int find(int i){
            return (parent[i] == i) ?  i : ( parent[i] = find( parent[i] ) ) ;
        }
        
        void unite(int x, int y){
            int s1 = find(x);
            int s2 = find(y);
            
            if(s1 != s2){
                if( rank[s1] < rank[s2]){
                    parent[s1] = s2;
                }else if(rank[s1] > rank[s2]){
                    parent[s2] = s1;
                }else{
                    parent[s1] = s2;
                    rank[s2]++;
                }
            }
        }
        
    

    };
  
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        
        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) {
            return a[2] < b[2];
        });

        
        DSU dsu(V);
        int wt=0, cnt=0;
        
        for(auto &e : edges){
            
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            if( dsu.find(u) != dsu.find(v) ){
                wt += w;
                dsu.unite(u,v);
                ++cnt;
                if(cnt == V-1) break;
            }
            
        }
        
        return wt;
    }
};
