class Solution {
public:

    int recSol(int i, bool buy, vector<int>& prices, vector<vector<int>>&dp){

        if(i < 0)
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];

        int inc=0, exc=0;
        if(buy){
            inc = recSol( i-1, 0, prices , dp) - prices[i];
            exc = recSol( i-1, 1, prices, dp );
        }else{
            inc = recSol( i-1, 1, prices, dp ) + prices[i];
            exc = recSol( i-1, 0, prices, dp );
        }

        return dp[i][buy] = max(inc, exc);
    }

    int maxProfit(vector<int>& prices) {
        bool buy = 1;
        int n = prices.size();
        reverse(prices.begin(), prices.end());
        vector<vector<int>>dp(n, vector<int>(2,-1));
        return recSol( n-1, buy, prices, dp );
    }
};