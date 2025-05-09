class Solution {
public:

     int solveMem( int i, vector<int>& nums, int n, vector<int>&dp){

        if(i >= n)
            return 0;
        
        if(dp[i] != -1)
            return dp[i];
        
        int inc = nums[i] + solveMem(i+2, nums, n, dp);
        int exc = solveMem(i+1, nums, n, dp);
        return dp[i] = max(inc, exc);
    }



    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1)
            return nums[0];

        vector<int>dp1(n+1, -1);
        int option1 = solveMem( 0, nums, n-1, dp1);

        vector<int>dp2(n+1, -1);
        int option2 = solveMem( 1, nums, n, dp2);
        return max(option1, option2);
        
    }
};