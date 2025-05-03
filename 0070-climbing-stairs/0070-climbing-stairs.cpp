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

    int solveSpaceOpt(int n){
       
        int prev1 = 0;
        int prev2 = 1;
        for(int i=2; i<n+2; i++){
            int curr = prev1 + prev2 ;
            prev1 = prev2;
            prev2 = curr;
        }
        return prev2;
    }

    int climbStairs(int n) {
        
        if(n == 0)
            return 0;

        vector<int>dp(n+1, -1);
        //return climbStairsMem(n, dp);
        //return solveTab(n);
        return solveSpaceOpt(n);
    }
};