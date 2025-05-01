class Solution {
  public:
    
    class BSTInfo {
        public:
            int max;
            int min;
            int size;
        BSTInfo(int max, int min, int size){
            this->max = max;
            this->min = min;
            this->size = size;
        }
    };
    
    BSTInfo largestBSTBT(Node *root) {
        
        if(!root){
            return BSTInfo(INT_MIN, INT_MAX, 0);
        }
        
        
        BSTInfo left = largestBSTBT(root->left);
        BSTInfo right = largestBSTBT(root->right);
        
        if( left.max < root->data && right.min > root->data ){
            return BSTInfo( max(root->data, right.max)  ,  min(root->data, left.min) , left.size+right.size+1 );
        }
        
        return BSTInfo(INT_MAX,INT_MIN, max( left.size, right.size  ) );
    }
    
    int largestBst(Node *root) {
        return largestBSTBT(root).size;
    }
};
