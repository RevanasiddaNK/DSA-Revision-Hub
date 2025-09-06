class Solution {
public:

    int solveMem(vector<int>& nums, int h, int n, vector<int>&dp){
        if(h >= n)
            return 0;
            
        if(dp[h] != -1) return dp[h];

        int inc = nums[h] + solveMem(nums, h+2, n, dp);
        int exc = solveMem(nums, h+1, n, dp);

        return dp[h] = max(inc, exc);
    } 

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, -1);
        int inc = solveMem(nums, 0, n-1, dp); // rob first house

        for(int i=0; i<=n; i++)
            dp[i] = -1;
            
        int exc = solveMem(nums, 1, n, dp); //not rob first house
        return max(inc, exc);
    }
};