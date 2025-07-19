class Solution {
public:

    // Returns true if all characters in pattern[0...j] are '*'
    bool checkAllStars(string& p, int j) {
        for(int k = 0; k <= j; k++) {
            if(p[k] != '*') return false;
        }
        return true;
    }

    bool memSol(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return true;
        if(j == 0) return false;
        if(i == 0) return checkAllStars(p, j-1);

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i-1] == p[j-1] || p[j-1] == '?') {
            return dp[i][j] = memSol(i-1, j-1, s, p, dp);
        }
        else if(p[j-1] == '*') {
            // * -> empty (i,j-1) or match (i-1,j)
            return dp[i][j] = memSol(i, j-1, s, p, dp) || memSol(i-1, j, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
        return memSol(m, n, s, p, dp);
    }
};
