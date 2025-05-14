class Solution {
public:
    // ------------------ Memoization ------------------
    int solveMem(int i, int end, vector<int>& nums, vector<int>& dp) {
        if (i > end) return 0;
        if (dp[i] != -1) return dp[i];

        int include = nums[i] + solveMem(i + 2, end, nums, dp);
        int exclude = solveMem(i + 1, end, nums, dp);

        return dp[i] = max(include, exclude);
    }

    // ------------------ Tabulation ------------------
    int solveTab(int start, int end, vector<int>& nums) {
        int len = end - start + 1;
        vector<int> dp(len + 2, 0);

        for (int i = end; i >= start; i--) {
            int idx = i - start;
            int include = nums[i] + dp[idx + 2];
            int exclude = dp[idx + 1];
            dp[idx] = max(include, exclude);
        }

        return dp[0];
    }

    int solveSpaceOpt(int start, int end, vector<int>& nums) {
    int next1 = 0; // dp[i+1]
    int next2 = 0; // dp[i+2]
    int curr = 0;

    for (int i = end; i >= start; i--) {
        int include = nums[i] + next2;
        int exclude = next1;
        curr = max(include, exclude);

        // shift window
        next2 = next1;
        next1 = curr;
    }

    return curr;
}


    // ------------------ Main Function ------------------
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // ---------- Memoization ----------
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
 /*       
        int option1 = solveMem(0, n - 2, nums, dp1); // exclude last
        int option2 = solveMem(1, n - 1, nums, dp2); // exclude first
*/

/*
        // ---------- Tabulation (alternative to memo) ----------
        int option1 = solveTab(0, n - 2, nums);
        int option2 = solveTab(1, n - 1, nums);
*/

        int option1 = solveSpaceOpt(0, n - 2, nums); // exclude last
        int option2 = solveSpaceOpt(1, n - 1, nums); // exclude first

        return max(option1, option2);
    }
};
