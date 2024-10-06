class Solution {
public:

    int recSol(vector<int>& prices, int i,bool buy){
        if(i ==  prices.size()){
           return 0;
        }

        int ans = 0;

        if(buy){
            int include = -prices[i] + recSol(prices,i+1,false);
            int exclude = recSol(prices,i+1,true);
            ans = max(include, exclude);
        }
        else{
            int include = prices[i] +  recSol(prices,i+1 ,true);
            int exclude = recSol(prices,i+1,false);
            ans = max(include, exclude);
        }

        return ans;
    }

    int solveMem( vector<int>& prices, int i,int buy,  vector<vector<int>>&dp ){

        if(i ==  prices.size()){
           return 0;
        }

        if(dp[i][buy] != -1)
            return dp[i][buy];

        int ans = 0;

        if(buy){
            int include = -prices[i] + solveMem(prices,i+1 ,0,dp);
            int exclude = solveMem(prices,i+1,1,dp);
            ans = max(include, exclude);
        }
        else{
            int include = prices[i] + solveMem(prices,i+1 ,1,dp);
            int exclude = solveMem(prices,i+1,0,dp);
            ans = max(include, exclude);
        }

        return dp[i][buy] = ans;
    }

    int solveTab( vector<int>& prices){
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2,0));
        int ans =0;
        for(int i=n-1; i>=0; i--){
            for(int b=1; b>=0; b--){
                if(b == 1){
                    int include = -prices[i] + dp[i+1][0];
                    int exclude = dp[i+1][1];
                    ans = max(include, exclude);
                }
                else{
                    int include = prices[i] + dp[i+1][1];
                    int exclude = dp[i+1][0];
                    ans = max(include, exclude);
                }
                dp[i][b] = ans;
            }
        }
        return dp[0][1];
    }

     int spaceOpt( vector<int>& prices){
        int n = prices.size();
        //vector<vector<int>>dp(n+1, vector<int>(2,0));
        vector<int>dp(2,0);
        int ans =0;
        for(int i=n-1; i>=0; i--){
            for(int b=1; b>=0; b--){
                if(b == 1){
                    int include = -prices[i] + dp[0];
                    int exclude = dp[1];
                    ans = max(include, exclude);
                }
                else{
                    int include = prices[i] + dp[1];
                    int exclude = dp[0];
                    ans = max(include, exclude);
                }
                dp[b] = ans;
            }
        }
        return dp[1];
    }



     

    int maxProfit(vector<int>& prices) {
        int p = 0;
        int i = 0;
        int n = prices.size();
        
        //return recSol(prices,i,1);

        vector<vector<int>>dp(n+1, vector<int>(2,-1));
        //return solveMem(prices,i,1,dp);
        
        //return solveTab(prices);

        return spaceOpt(prices);
       
    }
};