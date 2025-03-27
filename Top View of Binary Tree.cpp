/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
  
    void solveDFS(Node *root, int &mhd, int hd, int lvl,unordered_map<int, pair<int,int>>&mp){
        if(root == NULL)
            return;
        
        mhd = min(mhd, hd);
        if(mp.find(hd) == mp.end()){
            mp[hd] = make_pair(root->data, lvl);
        }
        else if(mp[hd].second > lvl )
            mp[hd] = make_pair(root->data, lvl);
            
        solveDFS(root->left, mhd, hd-1,lvl+1,mp); 
        solveDFS(root->right, mhd, hd+1,lvl+1,mp); 
    }
    
    
    void solveBFS(Node *root, int &mhd, unordered_map<int,int>&mp){
        if(root == NULL)
            return;
            
        queue<pair<Node*,int>>q;
        q.push(make_pair(root, 0));
          
        while(!q.empty()){
            
            Node* node = q.front().first;
            int hd = q.front().second;
            q.pop();
            
            if(mp.find(hd) == mp.end()){
                mp[hd] = node->data;
                mhd = min(mhd, hd);
            }
            if(node->left)
                q.push(make_pair(node->left, hd-1));
                
            if(node->right)
                q.push(make_pair(node->right, hd+1));
        }
    }
    
    vector<int> topView(Node *root) {
        //hd -> val , lvl
        //unordered_map<int, pair<int,int>>mp; //DFS
        int mhd = INT_MAX;
        //solveDFS(root, mhd, 0,0,mp); 
        
        unordered_map<int,int>mp; //BFS hd -. val
        solveBFS(root,mhd,mp);
        vector<int>ans;
        while(mp.find(mhd) != mp.end()){
            //ans.push_back( mp[mhd].first ); //DFS
            ans.push_back( mp[mhd] ); //BFS
            mhd++;
        }
        return ans;
    }
};
