
/*
[Approach – 1] Using Recursion – O(n) Time and O(h) Space
[Approach – 2] Using Iteration and Morris Traversal – O(n) Time and O(1) Space
*/
class Solution {
  public:
  
  bool isLeaf(Node* root){
      return (root->left == NULL && root->right == NULL );
  }
  
    
    void leftT(Node* root, vector<int>&ans){
        if(root == NULL)
            return;
            
        while( root && !isLeaf(root) ){
            ans.push_back(root->data);
            if(root->left)
                root = root->left;
            else if(root->right)
                 root  = root->right;  
        }
    }
  
    void rightT(Node* root, vector<int>&ans){
        if(root == NULL)
            return;

            
        while( root && !isLeaf(root) ){
            ans.push_back(root->data);
            if(root->right)
                root = root->right; 
            else if(root->left)
                root = root->left;  
        }
        
    }
    
    void leafT(Node* root, vector<int>&ans){
        while(root){
            if(!root->left){
                if(root->right == NULL){
                    ans.push_back(root->data);
                }
                root = root->right;
            }else{
                Node* prev = root->left;
                while(prev->right != NULL && prev->right != root ){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = root;
                    root = root->left;
                }
                else if(prev->right == root){
                    prev->right = NULL;
                    if(prev->left == NULL)
                        ans.push_back(prev->data);
                    root = root->right;
                }
            }
        }
        
    }
    
  
    vector<int> boundaryTraversal(Node *root) {
        vector<int>ans;
        if(root == NULL)
            return ans;
        if( !isLeaf(root)){
            ans.push_back(root->data);
        }
            
       
       leftT(root->left,ans);
       leafT(root, ans);
       int n = ans.size();
       rightT(root->right,ans);
       reverse(ans.begin()+n, ans.end());
       return ans;
    }
};
