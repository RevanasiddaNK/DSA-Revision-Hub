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

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        return solveMem(0, nums, n, dp);
    }
};