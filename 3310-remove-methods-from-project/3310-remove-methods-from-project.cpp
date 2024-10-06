class Solution {
public:

    void dfsTraversal( int node, unordered_map<int, vector<int> >&adjMap, vector<int>&visited){
        visited[node] = true;

        for(int neighNode : adjMap[node]){
            if(!visited[neighNode]){
                dfsTraversal( neighNode,adjMap, visited);
            }
        }

    }


    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_map<int, vector<int> >adjMap;
        for(auto edge : invocations ){
            int u = edge[0];
            int v = edge[1];
            adjMap[u].push_back(v);
        }

        vector<int>visited(n,0);
        dfsTraversal(k,adjMap, visited);

        bool isAllNodes = false;

        for(auto edge : invocations ){
            int u = edge[0];
            int v = edge[1];
            if(!visited[u] && visited[v]){
                isAllNodes = true;
                break;
            }
        }

        vector<int>ans;

        for(int node=0;node <n; node++){
            if(!visited[node] || isAllNodes)
                ans.push_back(node);
        }
        return ans;
    }
};