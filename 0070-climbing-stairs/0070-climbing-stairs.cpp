class Solution {
public:

    int solveMem(int i, int n, vector<int>&dp){

        if(i >= n)
            return i == n;
        
        if(dp[i] != -1)
            return dp[i];
        
        int one = solveMem(i+1, n, dp);
        int two = solveMem(i+2, n, dp);

        return dp[i] = one+two;
    
    }

    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return solveMem(0, n, dp);
    }
};