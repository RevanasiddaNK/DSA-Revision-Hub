class Solution {
public:

    int solveRec(string text1, string text2, int i, int j){
        if(i < 0 || j < 0)
            return 0;
        int m=0, nm1=0, nm2=0;
        if(text1[i] == text2[j]){
            m = 1 + solveRec( text1, text2, i-1, j-1);
        }else{
            nm1 = solveRec( text1, text2, i-1, j);
            nm2 = solveRec( text1, text2, i, j-1);
        }
        return max(m, max(nm1, nm2) );
    }

    int solveMem(string text1, string text2, int i, int j, vector<vector<int>>&dp){
        if(i == 0 || j == 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int m=0, nm1=0, nm2=0;
        if(text1[i-1] == text2[j-1]){
            m = 1 + solveMem(text1, text2, i-1, j-1, dp);
        }else{
            nm1 = solveMem( text1, text2, i-1, j, dp);
            nm2 = solveMem( text1, text2, i, j-1, dp);
        }
        return dp[i][j] =  max(m, max(nm1, nm2) );
    }

    int solveTab(string text1, string text2, int n1, int n2, vector<vector<int>>&dp){
        
        for(int i=0; i<n1; i++){
            dp[i][0] = 0;
        }

        for(int i=0; i<n2; i++){
            dp[0][i] = 0;
        }

        for(int i=1; i<n1; i++){
            for(int j=1; j<n2; j++){
                int m=0, nm1=0, nm2=0;
                if(text1[i-1] == text2[j-1]){
                    m = 1 + dp[i-1][j-1];
                }else{
                    nm1 = dp[i-1][j];
                    nm2 = dp[i][j-1];
                }
                dp[i][j] =  max(m, max(nm1, nm2) ); 
            }
        }
        return dp[n1-1][n2-1];
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>>dp( n1+1, vector<int>(n2+1, -1) );
        //return solveMem( text1, text2, n1, n2, dp);
        return solveMem( text1, text2, n1, n2, dp);
    }
};