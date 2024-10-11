class Solution {
public:

    vector<int> getPath(int src, int dest, vector<vector<int>>&adj){
            int n = adj.size();
            queue<int>q;
            vector<int> dist(n,-1), from(n,-1);

            dist[src] = 0;
            q.push(src);
            while(!q.empty()){
                int u  = q.front();
                q.pop();

                for(int v : adj[u] ){
                    if(dist[v] == -1){
                        dist[v] = dist[u] + 1;
                        from[v] = u;
                        q.push(v);
                    }
                }
            }

            vector<int>path;
            for(int node=dest; node != -1; node = from[node] ){
                path.push_back(node);
            }
            reverse(path.begin(), path.end());

            return path;
    }

    vector<vector<int>> handleSingleDimension(vector<vector<int>>&adj){
        int front=-1, rear=-1;
        int n = adj.size();

        for(int i=0; i<n; i++){

            if(adj[i].size() >= 2)
                continue;
            if(front == -1)
                front = i;
            else if(rear == -1){
                 rear = i;
                 break;
            }
    
        }

        if(rear == -1)
            return {};

        vector<int>path = getPath(front, rear, adj);
        return {path};

    }


    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {

     
            vector<vector<int>>adj(n);

            for(auto edge : edges){
                int u = edge[0], v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

            vector<vector<int>>ans = handleSingleDimension(adj);

            if(!ans.empty())
                return ans;
            
            vector<int>corners;
            for(int i=0; i<n; i++){
                if(adj[i].size() <= 2)
                    corners.push_back(i);
            }

            vector<int>path_lengths = {
                static_cast<int>( getPath(corners[0], corners[1], adj ).size() ),
                static_cast<int>( getPath(corners[0], corners[2], adj ).size() ),
                static_cast<int>( getPath(corners[0], corners[3], adj ).size() ),
            };

            int minIndex = min_element(path_lengths.begin(), path_lengths.end()) - path_lengths.begin() ;
            
            int cols = path_lengths[minIndex];
            int rows = n/cols;

            ans = vector<vector<int>>(rows, vector<int>(cols, -1));

            ans[0] = getPath(corners[0], corners[minIndex+1] ,adj);

            for(int r=0; r<rows-1; r++ ){
                for(int c=0; c <cols; c++){
                    set<int>neighbors;

                    if( r > 0) // top element
                        neighbors.insert(ans[r-1][c]);
                    if( c > 0) // left element
                        neighbors.insert(ans[r][c-1]);
                    if( c+1 < cols) // right
                        neighbors.insert(ans[r][c+1]);

                    int u = ans[r][c];

                    for(int v : adj[u]){
                        if(!neighbors.contains(v)){
                            ans[r+1][c] = v;
                            break;
                        }
                    }

                }
            }

            return ans;
    }
};