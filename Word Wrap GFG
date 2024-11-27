class Solution {
public:
    int helper(vector<int>nums, int k, int len, int i, int n,vector<vector<int>>&dp ) {
        
        if( i >= n ){
            return 0;
        }
        
        if( dp[i][len] != -1){
            return dp[i][len];
        }
        
        int newLen = len + 1 + nums[i];
        int cost1=INT_MAX, cost2=INT_MAX;
        
        if(newLen <= k) {
            //include in line
            cost1 = helper(nums,k,newLen,i+1,n, dp);
        }
        
        // exclude in line go to new line
        cost2 = (k-len) * (k-len) + helper(nums,k,nums[i] ,i+1,n, dp);
        
        return dp[i][len] = min(cost1, cost2);
    }

    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        int n = nums.size();
        
        vector<vector<int>>dp(n+1, vector<int>(k+1,-1));
        return helper(nums,k,nums[0],1,n, dp);
        
    } 
};

/*
Time Complexity: O(n*k)
Space Complexity: O(n*k)
*/
