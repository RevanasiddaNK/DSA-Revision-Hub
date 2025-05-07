class Solution {
public:
//This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.

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

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int> >adjList;

        int n = prerequisites.size();
        for(int i=0; i<n; i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }
        vector<bool>vis(numCourses, 0);
        vector<bool>dfsVis(numCourses, 0);
        for(int node=0; node<numCourses; node++){
            if(!vis[node]){
                bool hvCyc =  dfs(node, vis, dfsVis ,adjList); 
                if(hvCyc){
                    return 0;
                }
            }
        }
        return 1;
    }
};