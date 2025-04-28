class Solution {

  public:
  
    void inorderTraversal(Node* root, vector<int>& inorder) {
        if (!root)
            return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root->data);
        inorderTraversal(root->right, inorder);
    }
    
    int floorInorderTraversal(Node* root, int x) {
        vector<int>inorder;
        inorderTraversal(root,inorder);
        int ans = -1;
        for(int i : inorder){
            if(i > x){
                break;
            }else{
                ans = i;
            }
        }
        return ans;
    }
    
    int floorRec(Node* root, int x) {
        
        if(!root)
            return -1;
        
        if(root->data == x){
            return x;
        }
        else if(root->data < x){
            
            int r = floorRec(root->right , x);
            return max(r, root->data);
        }else{
            return floorRec(root->left , x);
        }
    }
    
    int floorIterative(Node*  root, int x) {
        Node* curr = root;
        int ans = -1;
        while(curr){
            
            if(curr->data == x){
                return x;
            }
            else if(curr->data <= x){
                ans = max(ans, curr->data);
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
        return ans;
    }
    
    
    int floor(Node* root, int x) {
        //return floorInorderTraversal(root,x);
        //return floorRec(root,x);
        return floorIterative(root,x);
    }
};
