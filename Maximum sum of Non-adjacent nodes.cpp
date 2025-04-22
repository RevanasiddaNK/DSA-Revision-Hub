//Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
  
    int recSol(Node* root){
        
        if(!root)
            return 0;
            
        int inc = root->data, exc=0;
        if(root->left){
            inc += recSol(root->left->left);
            inc += recSol(root->left->right);
        }
        
        if(root->right){
            inc += recSol(root->right->left);
            inc += recSol(root->right->right);
        }
        
        exc += recSol(root->right);
        exc += recSol(root->left);
        
        return max(inc,exc);
    }
    
    pair<int,int> maxSumHelper(Node* root){
        
        if(!root)
            return make_pair(0,0);
            
        pair<int,int>sum1 = maxSumHelper(root->left);
        pair<int,int>sum2 = maxSumHelper(root->right);
        
        int incl = root->data + sum1.second + sum2.second;
        int excl = max(sum1.first, sum1.second) + max(sum2.first,sum2.second);
        
        return make_pair(incl,  excl );
    }
    
    pair<int,int> maxSumHelperMemoize(Node* root, unordered_map<Node*, pair<int,int> >&dp){
        
        if(!root)
            return make_pair(0,0);
        
        if(dp.find(root) != dp.end())
            return dp[root];
            
        pair<int,int>sum1 = maxSumHelperMemoize(root->left,dp);
        pair<int,int>sum2 = maxSumHelperMemoize(root->right,dp);
        
        int incl = root->data + sum1.second + sum2.second;
        int excl = max(sum1.first, sum1.second) + max(sum2.first,sum2.second);
        
        return  dp[root] = make_pair(incl,  excl );
    }
  
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        int ans = -1;
        //ans  = recSol(root);
        
        //pair<int,int>p = maxSumHelper(root);
        
        unordered_map<Node*, pair<int,int> >dp;
        pair<int,int>p = maxSumHelperMemoize(root,dp);
        
        
        ans = max(p.first, p.second);
        
        
        return ans;
        
    }
};
