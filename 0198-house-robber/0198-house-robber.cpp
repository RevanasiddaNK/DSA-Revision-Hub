class Solution {
public:

    int solveMem(int i, vector<int>& nums, bool alarm, vector<vector<int>>&dp ){
        if(i < 0){
            return 0;
        }

        if(dp[i][alarm] != -1){
            return dp[i][alarm];
        }

        int money = 0;
        if(alarm){
            money = solveMem(i-1, nums, !alarm, dp );
        }else{
            int steal = nums[i] + solveMem(i-1, nums, !alarm, dp );
            int notSteal = solveMem(i-1, nums, alarm, dp );
            money = max(steal,notSteal );
        }
        return dp[i][alarm] = money;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1) );
        bool alarm = false;
        return solveMem(n-1, nums, alarm, dp );
    }
};