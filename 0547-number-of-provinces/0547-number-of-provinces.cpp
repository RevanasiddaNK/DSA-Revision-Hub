class Solution {
public:

    class DSU{
        public:
        vector<int>rank;
        vector<int>parent;

        DSU(int n){
            rank.resize(n,0);
            parent.resize(n,0);
            for(int i=0; i<n; i++)
                parent[i] = i;
        }

        int find(int i){
            return parent[i] == i ? i : parent[i] = find(parent[i]);
        }

        void unite(int n1, int n2){

            int pn1 = find(n1);
            int pn2 = find(n2);
            // attach smaller tree under bigger tree
            if( rank[pn1] < rank[pn2] ){
                parent[pn1] = pn2;
            }else if(rank[pn1] > rank[pn2]){
                parent[pn2] = pn1;
            }else{
                parent[pn2] = pn1;
                rank[pn1]++;
            }
        }

    };


    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        DSU dsu(n); 

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                if(isConnected[i][j] ){
                    dsu.unite(i,j);
                }
            }
        }

        int np = 0;
        for(int i=0; i<n; i++){
            if(dsu.parent[i] == i)
                np++;
        }
        return np;
    }
};