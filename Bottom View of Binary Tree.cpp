//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
  
    void solveDFS(Node *root, int hd, int lvl, int &minHD, unordered_map<int, pair<int,int> >&mp) {
        if(!root)
            return;
        
        minHD = min(hd, minHD);
           
        if(mp.find(hd) == mp.end()){
           mp[hd] = make_pair(root->data, lvl); 
        }
        else if(mp[hd].second <= lvl){
            mp[hd] = make_pair(root->data, lvl); 
        }
        
        solveDFS(root->left, hd-1, lvl+1, minHD, mp);
        solveDFS(root->right, hd+1, lvl+1, minHD, mp);
    }
  
    void solveBFS(Node *root, int &minHD, unordered_map<int, int>&mp) {
        
        if(!root)
            return;
        
        queue<pair<Node*, int>>q;
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            
            Node* curr = q.front().first;
            int hd = q.front().second;
            q.pop();
            minHD = min(minHD, hd);
            mp[hd] = curr->data;
            
            if(curr -> left)
                q.push(make_pair(curr->left,hd-1));
            
            if(curr -> right)
                q.push(make_pair(curr->right,hd+1));
        }
    } 
  
    vector<int> bottomView(Node *root ) {
        
        vector<int>ans;
        //unordered_map<int, pair<int,int> >mp;   //DFS
        unordered_map<int, int>mp;  //BFS
        int minHD = 0;
        
        //solveDFS(root, 0, 0, minHD, mp);
        
        solveBFS(root, minHD,mp);
        
        int hd = minHD;
        while(mp.find(hd) != mp.end()){
           // ans.push_back(mp[hd].first);    //DFS
            ans.push_back(mp[hd]);
            hd++;
        }
        return ans;
    }
};
