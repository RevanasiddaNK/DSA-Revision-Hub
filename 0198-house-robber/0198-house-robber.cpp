class Solution {
public:

    int solveMem( int i, vector<int>& nums, int n, vector<int>&dp){

        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int inc = nums[i] + solveMem(i+2, nums, n, dp);
        int exc = solveMem(i+1, nums, n, dp);
        return dp[i] = max(inc, exc);
    }

    int solveTab(vector<int>& nums, int n, vector<int>&dp){

        dp[n] = 0;
        dp[n+1] = 0;
        for(int i=n-1; i>=0; i--){
            int inc = nums[i] + dp[i+2];
            int exc = dp[i+1];
            dp[i] = max(inc, exc);
        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+2, -1);
        //return solveMem(0, nums, n, dp);
        return solveTab( nums, n, dp);
    }
};