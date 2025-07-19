class Solution {
public:

    int solveMem(int i, bool buy, int txn, vector<int>& prices, vector<vector<vector<int>>>&dp){
        if(i < 0)
            return 0;
        if(txn <= 0){
            return 0;
        }

        if(dp[i][buy][txn] != -1)
            return dp[i][buy][txn];

        int inc=0, exc=0;
        if(buy){
            inc = solveMem( i-1, 0, txn, prices , dp) - prices[i];
            exc = solveMem( i-1, 1, txn, prices, dp );
        }else{
            inc = solveMem( i-1, 1, txn-1, prices, dp ) + prices[i];
            exc = solveMem( i-1, 0, txn, prices, dp );
        }

        return dp[i][buy][txn] = max(inc, exc);
    }

    int maxProfit(vector<int>& prices) {
        int txn=2;
        int n = prices.size();
        reverse(prices.begin(), prices.end());
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)  ) );
       return solveMem( n-1, 1, txn, prices , dp);
    }
};