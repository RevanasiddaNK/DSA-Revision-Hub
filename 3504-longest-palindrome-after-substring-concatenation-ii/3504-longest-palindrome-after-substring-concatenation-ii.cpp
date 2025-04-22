class Solution {
public:
    int longestPalindrome(string s, string t) {
         int ans = INT_MIN;
      
        int m = s.size(), n = t.size();
          // from i till j longest palindrome
        vector<vector<bool>>ps(m, vector<bool>(m,false));
        vector<int>maxs(m,0);
        for(int i=m-1; i>= 0; i--){
            for(int j=i; j<m; j++){
                ps[i][j] = (i == j) || (i+1 == j && s[i] == s[j]) || (  s[i] == s[j]  && ps[i+1][j-1] );

                if(ps[i][j]){
                    maxs[i] = max( maxs[i] , j-i+1  );
                    ans = max(ans,  maxs[i]);
                }
            }
        }

        vector<vector<bool>>pt(n, vector<bool>(n,false));
        vector<int>maxt(n,0);
        for(int i=n-1; i>= 0; i--){
            for(int j=i; j<n; j++){

                pt[i][j] = (i == j) || (i+1 == j && t[i] == t[j]) || (  t[i] == t[j]  && pt[i+1][j-1] );

                if(pt[i][j]){
                    maxt[j] = max( maxt[j] , j-i+1  );
                    ans = max(ans,  maxt[j]);
                }
            }
        }




        // dp[i][j] = dp[i-1][j+1] + 2;
        vector<vector<int>>dp(m, vector<int>(n, 0) );
        for(int i=0; i<m; i++){
            for(int j=n-1; j>=0; j--){
                if(s[i] == t[j]){
                    if(j+1 < n && i-1 >= 0){
                        dp[i][j] =  dp[i-1][j+1] + 2;
                    }else{
                        dp[i][j] = 2;
                    }
                    int extra = 0;
                    if(i+1 < m) extra = max(extra, maxs[i+1]  );
                    if(j-1 >= 0)  extra = max(extra, maxt[j-1]  );
                    ans = max(ans, extra + dp[i][j] );
                }
            }
        }
        return ans;
    }
};