/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
  
    void RecTraverse(Node *root, int &minD,int d, unordered_map<int, vector<int> >&mp){
        
        if(!root){
            return;
        }
        
        mp[d].push_back( root->data );
        minD = min(minD, d);
        
        RecTraverse(root->left, minD, d+1, mp);
        RecTraverse(root->right, minD, d, mp);
        
    }
  
    void iterativeSol(Node *root, vector<int>&ans){
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
           Node* curr = q.front();
           q.pop();
           
           while(curr){
               ans.push_back(curr->data);
               if(curr->left)
                    q.push(curr->left);
                curr = curr->right;
           }
        }
    }
  
    vector<int> diagonal(Node *root) {
        
        vector<int>ans;
        
        iterativeSol(root, ans);
        
        /*
        unordered_map<int, vector<int> >mp;
        int minD = INT_MAX;
        RecTraverse(root, minD, 0, mp);
        
        int i=0;
        while(mp.find(i) != mp.end()){
           
            for(int el : mp[i]){
                ans.push_back(el);
            }
            i++;
        }
        */
        
        return ans;
    }
};
