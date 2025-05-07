class Solution {
public:

    int solveRec(int i, int j, int m, int n){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i >= m || j>= n){
            return 0;
        }

        int down = solveRec(i+1,j,m,n);
        int right = solveRec(i,j+1,m,n);

        return down+right;
    }

    int solveMem(int i, int j, int m, int n, vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }

        if(i >= m || j>= n){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int down = solveMem(i+1,j,m,n,dp);
        int right = solveMem(i,j+1,m,n,dp);

        return dp[i][j] = down+right;
    }

    int solveTab(int m, int n, vector<vector<int>>&dp){

        dp[m-1][n-1] = 1;

        for(int i=0; i<m; i++)
            dp[i][n] = 0;

        for(int j=0; j<n; j++)
            dp[m][j] = 0;
        
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1)
                    continue;
                dp[i][j] = dp[i+1][j] + dp[i][j+1] ;
            }
        }
        return dp[0][0];
    }
/*
    int solveSpaceOpt(int m, int n){
        vector<int>prev(n, 0);
        prev[n-1] = 1;
        for(int i=m-1; i>=0; i--){
            vector<int>temp(n, 0);
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1)
                    continue;
                //dp[i][j] = dp[i+1][j] + dp[i][j+1] ;
                int right=0, down=0;
                if(j+1 < n)
                    right = temp[j+1];
                if(i < n)
                    down = prev[i];
                temp[j] = down + right;
            }
            prev = temp;
        }
        return prev[0];
    }
*/

int solveSpaceOpt(int m, int n){
    vector<int> prev(n, 0);
    for(int i = m - 1; i >= 0; i--){
        vector<int> temp(n, 0);
        for(int j = n - 1; j >= 0; j--){
            if(i == m - 1 && j == n - 1){
                temp[j] = 1;
            } else {
                int down = 0, right = 0;
                if(i + 1 < m)
                    down = prev[j];
                if(j + 1 < n)
                    right = temp[j + 1];
                temp[j] = down + right;
            }
        }
        prev = temp;
    }
    return prev[0];
}

    

    int uniquePaths(int m, int n) {
        //return solveRec(0,0,m,n);
        vector<vector<int>>dp(m+1, vector<int>(n+1,-1));
        //return solveMem(0,0,m,n,dp);
        //return solveTab(m, n, dp);

        return solveSpaceOpt(m,n);
    }
};