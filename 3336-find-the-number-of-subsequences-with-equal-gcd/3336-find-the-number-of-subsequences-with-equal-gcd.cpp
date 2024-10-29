
class Solution {
public:
    const int MOD = 1000000007;

    // Function to calculate GCD of two numbers
    int getGCD2Num(int a, int b) {
        int n2 = min(a, b);
        int n1 = max(a, b);

        while (n2 != 0) {
            int d = n1 % n2;
            n1 = n2;
            n2 = d;
        }
        return n1;
    }

    // Modular addition function
    int add(int a, int b, int c) {
        return ((a + b) % MOD + c) % MOD;
    }

    // Recursive function to count pairs of subsequences with equal GCD
    int getCount(vector<int>& nums, int i, int gcd1, int gcd2) {
        // Base case: when we've processed all elements
        if(i == nums.size()) {
            // Count only if both subsequences have the same GCD, and both are non-trivial
            return (gcd1 == gcd2) ? 1 : 0;
        }

        // 3 options: 
        // Option 1: Add nums[i] to the first subsequence
        int g1 = getCount(nums, i + 1, getGCD2Num(gcd1, nums[i]), gcd2);
        // Option 2: Add nums[i] to the second subsequence
        int g2 = getCount(nums, i + 1, gcd1, getGCD2Num(gcd2, nums[i]));
        // Option 3: Skip nums[i] and continue with both subsequences unchanged
        int g3 = getCount(nums, i + 1, gcd1, gcd2);

        // Sum up the counts from all options
        return add(g1, g2, g3);
    }

    int getCountMem(vector<int>& nums, int i, int gcd1, int gcd2,            vector<vector<vector<int>>>&dp) {
        // Base case: when we've processed all elements
        if(i == nums.size()) {
            // Count only if both subsequences have the same GCD, and both are non-trivial
            return (gcd1 == gcd2) ? 1 : 0;
        }

        if( dp[i][gcd1][gcd2] != -1 ){
            return dp[i][gcd1][gcd2] ;
        }

        // 3 options: 
        // Option 1: Add nums[i] to the first subsequence
        int g1 = getCountMem(nums, i + 1, getGCD2Num(gcd1, nums[i]), gcd2, dp);
        // Option 2: Add nums[i] to the second subsequence
        int g2 = getCountMem(nums, i + 1, gcd1, getGCD2Num(gcd2, nums[i]), dp);
        // Option 3: Skip nums[i] and continue with both subsequences unchanged
        int g3 = getCountMem(nums, i + 1, gcd1, gcd2, dp);

        // Sum up the counts from all options
        return dp[i][gcd1][gcd2] = add(g1, g2, g3);
    }

    int subsequencePairCount(vector<int>& nums) {
        // Edge case: If nums is empty or contains only one element, no valid pairs are possible
        if (nums.size() < 2) {
            return 0;
        }
        //return getCount(nums, 0, 0, 0,dp )-1;
        int n = nums.size();

        vector<vector<vector<int> > >dp(n+1, vector<vector<int> >(201, vector<int>(201, -1)));
        //dp[0][0][0] = 1;

        return getCountMem(nums,0,0,0, dp) -1;


     
        
    }
};
