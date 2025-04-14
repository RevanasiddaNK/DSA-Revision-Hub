class Solution {
  public:
  
  
    int countPathsFromNode(Node* node, int k, int currentSum) {
        
        if(!node)
            return 0;
            
        int pathcount  = 0;
        currentSum += node->data;
        if(currentSum == k){
            pathcount++;
        }
        
        pathcount += countPathsFromNode(node->left, k, currentSum);
        pathcount += countPathsFromNode(node->right, k, currentSum);
        
        return pathcount;
    }
  
    int sumKSolve(Node *root, int k) {
        if(!root)
            return 0;
            
        int res  = countPathsFromNode(root, k, 0);
        
        res += sumKSolve(root->left, k);
        res += sumKSolve(root->right, k);
        
        return res;
    }
    
    int solvePrefixSum(Node* root, int k, int currSum, unordered_map<int,int>&mp){
        if(!root)
            return 0;
            
        int pathCount = 0;
        
        currSum += root->data;
        
        if(currSum == k){
            pathCount++;
        }
    
        pathCount += mp[currSum-k];
        
        mp[currSum]++;
        
        pathCount += solvePrefixSum(root->left,k,currSum,mp  );
        pathCount += solvePrefixSum(root->right,k,currSum,mp  );
        mp[currSum]--;
        return pathCount;
    }
    
    int sumK(Node *root, int k) {
        int ans = -1;
        //ans = sumKSolve(root, k);
        unordered_map<int,int>mp;
        ans  = solvePrefixSum(root,k,0,mp  );
        return ans;
    }
};
