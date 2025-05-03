class Solution {
public:

    int climbStairsMem(int n, vector<int>&dp) {
        if(n <= 0)
            return  n+1;
        if(dp[n]  != -1)
            return dp[n];
        return  dp[n] = climbStairsMem(n-1, dp) + climbStairsMem(n-2, dp);
    }

    int solveTab(int n){
        vector<int>dp(n+2, -1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<n+2; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n+1];
    }

    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        //return climbStairsMem(n, dp);
        return solveTab(n);
    }
};