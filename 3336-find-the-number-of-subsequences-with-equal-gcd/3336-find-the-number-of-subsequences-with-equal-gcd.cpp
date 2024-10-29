
class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MX = 200;  

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

     int subsequencePairCountSpaceOpt(vector<int>&a) {
        int n = a.size();
        
        // 2D DP table to count pairs of subsequences with GCD x and y
        vector<vector<int>> dp(MX + 1, vector<int>(MX + 1, 0));
        
        // Initialize dp[0][0] = 1, representing the count for two empty subsequences
        dp[0][0] = 1;
        
        // Process each element in the input array
        for (int i = 0; i < n; i++) {
            // Temporary DP table for updates on current element `a[i]`
            vector<vector<int>>ndp(MX + 1, vector<int>(MX + 1, 0));
            
            // Traverse all GCD pairs (x, y) in the dp table
            for (int x = 0; x <= MX; x++) {
                for (int y = 0; y <= MX; y++) {
                    if (dp[x][y] == 0) continue; // Skip if no pairs with GCDs x and y

                    // Option 1: Do not include `a[i]` in either subsequence
                    ndp[x][y] = add(ndp[x][y], dp[x][y],0);
                    
                    // Option 2: Include `a[i]` in the first subsequence, update its GCD
                    int newGCD1 = gcd(x, a[i]);
                    ndp[newGCD1][y] = add(ndp[newGCD1][y], dp[x][y],0);
                    
                    // Option 3: Include `a[i]` in the second subsequence, update its GCD
                    int newGCD2 = gcd(y, a[i]);
                    ndp[x][newGCD2] = add(ndp[x][newGCD2], dp[x][y],0);
                }
            }
            
            // Update the dp table with values from the current element's ndp
            dp = ndp;
        }
        
        int ans = 0;
        // Sum counts where both subsequences have the same GCD `i`
        for (int i = 1; i <= MX; i++) {
            ans = add(ans, dp[i][i],0);
        }
        
        return ans;
    }


    int subsequencePairCount(vector<int>& nums) {
        // Edge case: If nums is empty or contains only one element, no valid pairs are possible
        if (nums.size() < 2) {
            return 0;
        }
        //return getCount(nums, 0, 0, 0,dp )-1;
        int n = nums.size();

        vector<vector<vector<int> > >dp(n+1, vector<vector<int> >(MX+1 , vector<int>(MX+1, -1)));
        //return getCountMem(nums,0,0,0, dp) -1;


        return subsequencePairCountSpaceOpt(nums);

     
        
    }
};

/*
TC : O(3^N*N)
SC : O(N^3) dp & O(N) recursive call stack
Revise space optimix=zed sol while studying dp
*/


