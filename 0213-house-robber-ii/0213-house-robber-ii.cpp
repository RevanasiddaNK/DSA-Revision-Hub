class Solution {
public:

    int solveMem( int i, bool fh, vector<int>& nums, int n, vector<vector<int>>&dp){

        if(i >= n)
            return 0;
        
        if(dp[i][fh] != -1)
            return dp[i][fh];

        int inc=0, exc=0;
        if(!(fh && i== n-1))
            inc = nums[i] + solveMem(i+2, fh, nums, n, dp);
        exc = solveMem(i+1, fh, nums, n, dp);

        return dp[i][fh] = max(inc, exc);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return max( solveMem(1, 0, nums, n, dp), nums[0] + solveMem(2, 1, nums, n, dp) );
    }
};