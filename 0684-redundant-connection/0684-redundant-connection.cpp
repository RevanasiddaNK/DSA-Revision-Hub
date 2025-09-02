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



    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        unordered_set<int>st;
        for(auto e : edges){
            st.insert(e[0]);
            st.insert(e[1]);
        }

        int n = st.size();

        DSU dsu(n+1);

        for(auto e : edges){
            int n1 = e[0];
            int n2 = e[1];
            int p1 = dsu.find(n1);
            int p2 = dsu.find(n2);

            if(p1 == p2){
                return vector<int>({n1,n2});
            }else{
                dsu.unite(n1,n2);
            }
        }
        return vector<int>({-1,-1});
    }
};