class Solution {
public:
    
    int solveMem(int i, int end, vector<int>& nums, vector<int>& dp) {
        if (i > end) return 0;
        if (dp[i] != -1) return dp[i];

        int include = nums[i] + solveMem(i + 2, end, nums, dp);
        int exclude = solveMem(i + 1, end, nums, dp);

        return dp[i] = max(include, exclude);
    }

    int solveTab(int s, int e,  vector<int>& nums){

        int n = e-s+1;
        vector<int>dp(n+2, 0);
    
        for(int i=e; i>=s; i--){

            int index = i-s;
            int include = nums[i] + dp[index + 2];
            int exclude = dp[index+1];
            dp[index] = max(include, exclude);

        }
        return dp[0];
    }

    // ------------------ Main Function ------------------
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

/*
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int option1 = solveMem(0, n - 2, nums, dp1); // exclude last
        int option2 = solveMem(1, n - 1, nums, dp2); // exclude first
*/


        // ---------- Tabulation (alternative to memo) ----------
        int option1 = solveTab(0, n - 2, nums);
        int option2 = solveTab(1, n - 1, nums);

/*
        int option1 = solveSpaceOpt(0, n - 2, nums); // exclude last
        int option2 = solveSpaceOpt(1, n - 1, nums); // exclude first
*/
        return max(option1, option2);
    }
};
