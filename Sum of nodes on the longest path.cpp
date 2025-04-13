
/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
  
    int findDepth(Node *root){
        if(!root)
            return 0;
        int l = findDepth(root->left);
        int r = findDepth(root->right);
        return max(l,r)+1;
    }
  
    int BruteForceSol(Node *root) {
        if(!root){
            return 0;
        }
        
        int l = findDepth(root->left);
        int r = findDepth(root->right);
        
        if(l == r){
            return root->data + max(BruteForceSol(root->left),  BruteForceSol(root->right) );
        }
        else if(l > r)
            return root->data + BruteForceSol(root->left);
        else{
            return root->data + BruteForceSol(root->right);
        }
    }
  
    void recSol(Node *root, int len, int sum, int &maxLen, int &maxSum ){
        
        if(!root){
            
            if(len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            else if (len == maxLen && sum > maxSum) {
                maxSum = sum;
            }
            return;
        }
           
        recSol( root->right, len+1,  sum+root->data, maxLen, maxSum  );
        recSol( root->left, len+1,  sum+root->data, maxLen, maxSum  );
     
    }
    
    pair<int,int> getMax(Node *root){
        if(root == NULL){
            return make_pair(0,0);
        }
        if(root->left == NULL && root->right == NULL){
            return make_pair(root->data,1);
        }
        
        pair<int,int>p1 =  getMax(root->left);
        pair<int,int>p2 =  getMax(root->right);
        if(p1.second == p2.second){
            if(p1.first >= p2.first){
                return make_pair(p1.first+root->data, p1.second+1);
            }else{
                return make_pair(p2.first+root->data, p2.second+1);
            }
        }
        
        return p1.second > p2.second ? make_pair(p1.first+root->data, p1.second+1) : make_pair(p2.first+root->data, p2.second+1);
        
    }
    
    
    int levelOrderSol(Node* root){
        
        int maxLen = INT_MIN, maxSum = INT_MIN;
        
        queue<pair<Node*,pair<int,int>>>q;
        
        q.push( make_pair(root, make_pair(root->data,1) ) );
        
        while(!q.empty()){
            
            auto f = q.front();
            q.pop();
            Node* curr = f.first;
            
            if(!curr->left && !curr->right){
                
                if(maxLen < f.second.second ){
                    maxLen = f.second.second;
                    maxSum = f.second.first;
                }
                else if(maxLen == f.second.second ){
                    maxSum = max(f.second.first, maxSum);
                }
            }
            
            if(curr->left){
                q.push( make_pair(curr->left, make_pair(f.second.first+curr->left->data, f.second.second+1) ) );
            }
            
            if(curr->right){
                q.push( make_pair(curr->right, make_pair(f.second.first+curr->right->data, f.second.second+1) ) );
            }
        }
        return  maxSum;
    }
  
    int sumOfLongRootToLeafPath(Node *root) {
        
        int ans = -1;
        
       //ans =  BruteForceSol(root);
        ans = levelOrderSol(root);
        
    /*   
        int maxLen = INT_MIN, maxSum = INT_MIN;
        recSol(root, 0,0, maxLen,  maxSum);
        ans = maxSum;
    */
        
    /*
        pair<int,int>p1 =  getMax(root);
        ans = p1.first;
    */
    
       return ans;
    }
};
