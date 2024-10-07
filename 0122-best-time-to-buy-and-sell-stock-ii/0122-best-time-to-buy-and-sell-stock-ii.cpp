class Solution {
public:

    int solveMem(vector<int>& prices, int i, int buy, vector< vector<int>>&dp ){
        if(i >= prices.size())
            return 0;

        if(dp[i][buy] != INT_MIN)
            return dp[i][buy];

        int profit = 0;
        if(buy){
            int inc = -prices[i] + solveMem(prices,i+1,0,dp);
            int exc = solveMem(prices,i+1,1,dp);
            profit = max(inc, exc);
        }
        else{
            int inc = prices[i] + solveMem(prices,i+1,1,dp);
            int exc = solveMem(prices,i+1,0,dp);
            profit = max(inc, exc);
        }
        return dp[i][buy] = profit;
    }

    int solveTab(vector<int>& prices,int n){
        vector< vector<int> >dp(n+1, vector<int>(2,0));

        for(int i=n-1; i>=0; i--){
            for(int b=0; b<2; b++){
                int profit = 0;
                if(b){
                    int inc = -prices[i] + dp[i+1][0];
                    int exc = dp[i+1][1];
                    profit = max(inc, exc);
                }
                else{
                    int inc = prices[i] + dp[i+1][1];
                    int exc = dp[i+1][0];
                    profit = max(inc, exc);
                }

                dp[i][b] = profit;
            }
        }
        return dp[0][1];
    }

     int solveSpaceOpt(vector<int>& prices,int n){
        
        vector<int>dp(2,0);
        for(int i=n-1; i>=0; i--){
          
            for(int b=0; b<2; b++){
                int profit = 0;
                if(b){
                    int inc = -prices[i] + dp[0];
                    int exc = dp[1];
                    profit = max(inc, exc);
                }
                else{
                    int inc = prices[i] + dp[1];
                    int exc = dp[0];
                    profit = max(inc, exc);
                }

                dp[b] = profit;
            }
        }
        return dp[1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
      
        vector< vector<int> >dp(n+1, vector<int>(2, INT_MIN));
        //return solveMem(prices,0,1,dp);

        //return solveTab(prices, n);

        return solveSpaceOpt(prices, n);

    }
};

/*
TC : O(N)
SC : O(N)
*/