class Solution {
public:

    class DSU{

        public: 
        vector<int>parent;
        vector<int>rank;

        DSU(int n){
            parent.resize(n,-1);
            rank.resize(n,0);

            for(int i=0; i<n; i++)
                parent[i] = i;
        }

        int find(int i){
            return parent[i] == i ? i : parent[i] = find(parent[i]);
        }

        void unite(int n1, int n2){
            int p1 = find(n1);
            int p2 = find(n2);

            if( rank[p1] < rank[p2]  ){
                parent[p1] = p2;
            }
            else if( rank[p1] > rank[p2]  ){
                parent[p2] = p1;
            }else{
                parent[p2] = p1;
                rank[p1]++;
            }
        }
    };


    int makeConnected(int n, vector<vector<int>>& connections) {

        DSU dsu(n);
        
        int cntRedConn = 0;
        int size = connections.size();

        for(int i=0; i<size; i++){
            int p1 = dsu.find(connections[i][0]);
            int p2 = dsu.find(connections[i][1]);
            if(p1 == p2){
                cntRedConn++;
            }else{
                dsu.unite(connections[i][0], connections[i][1]);
            }
        }
        int cntNotConn = 0;
        for(int i=0; i<n; i++){
            if(dsu.find(i) == i)
                cntNotConn++;
        }

        return cntNotConn-1 <= cntRedConn ? cntNotConn-1 : -1;
    }
};