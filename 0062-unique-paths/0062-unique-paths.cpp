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

    int uniquePaths(int m, int n) {
        //return solveRec(0,0,m,n);
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return solveMem(0,0,m,n,dp);
    }
};