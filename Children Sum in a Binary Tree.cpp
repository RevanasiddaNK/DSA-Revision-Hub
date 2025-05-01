class Solution {
  public:
   
    int isSumPropertyRec(Node *root) {
        
        if(!root || !( root->left || root->right) )
            return 1;
        
        int sum=0;
        
        if( root->left ){
            sum +=  root->left->data;
        }
         
        if(root->right){
             sum += root->right->data;
        }
        
        return (sum == root->data) && ( isSumPropertyRec(root->left) && isSumPropertyRec(root->right)   );
        
    }
    
    int isSumPropertyIterative(Node* root) {
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            
            Node* f = q.front();
            q.pop();
            
            int sum = 0;
            
            if(!(f->left || f->right   ))
                continue;
            
            if(f->left){
                sum += f->left->data;
                q.push(f->left);
            }
            
                
            if(f->right){
                sum += f->right->data;
                q.push(f->right);
            }
                
            
            if(sum != 0 && sum != f->data){
                return 0;
            }
        }
        return 1;
    }
    
    int isSumProperty(Node *root) {
        //return isSumPropertyRec(root);
        return isSumPropertyIterative(root);
    }
};
