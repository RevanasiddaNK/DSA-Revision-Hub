class Solution {
public:

    int solve(vector<int>& nums, int i, int n,bool fh, vector<vector<int>>&dp) {

        if(i >= n){
            return 0;
        }

        if(dp[i][fh] != -1){
            return dp[i][fh];
        }
        int rob = rob = nums[i] +  solve(nums,i+2,n,fh,dp);

        if( i == n-1 && fh){
            rob = 0;
        }

       int leave = 0 +  solve(nums,i+1,n,fh,dp);


       return dp[i][fh] = max(rob, leave);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(2,-1));


    
        return max( solve(nums,1,n,0,dp) , nums[0] + solve(nums,2,n,1,dp)  )  ;
    }
};