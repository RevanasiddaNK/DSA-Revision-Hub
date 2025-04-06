class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Step 1: Compute prefix sum array (not used later, maybe leftover)
        long long pref[n+1];
        pref[0] = 0;
        for(int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + nums[i];
        }

        // dp[i][j] will store the minimum cost to form j segments of size x using the first (i+1) elements
        vector<vector<long long>> dp(n, vector<long long>(k+1, 1e18));

        // median[i] stores the cost of making a subarray of size x (starting at index i) equal to its median
        vector<long long> median;

        // Step 2: Preprocess median cost for all sliding windows of size x
        {
            multiset<int> low, high; // low stores smaller half, high stores larger half
            long long sum1 = 0, sum2 = 0;

            // Initialize first window [0...x-1]
            for(int i = 0; i < x; i++) {
                low.insert(nums[i]);
                sum1 += nums[i];
            }

            // Balance the two multisets so that 'low' holds the smaller (x+1)/2 elements
            while(low.size() > (x+1)/2) {
                sum1 -= *low.rbegin();
                sum2 += *low.rbegin();
                high.insert(*low.rbegin());
                low.erase(prev(low.end()));
            }

            // Calculate cost for the first window and store in median
            // Cost = sum of absolute differences from the median
            median.push_back(-(sum1 - 1LL * low.size() * (*low.rbegin()) + 1LL * high.size() * (*low.rbegin()) - sum2));

            // Slide the window one step at a time and repeat
            for(int i = x; i < n; i++) {
                // Remove outgoing element
                if(low.size() && *low.rbegin() >= nums[i - x]) {
                    sum1 -= nums[i - x];
                    low.erase(low.find(nums[i - x]));
                } else {
                    sum2 -= nums[i - x];
                    high.erase(high.find(nums[i - x]));
                }

                // Insert new incoming element
                if(low.size() && nums[i] <= *low.rbegin()) {
                    sum1 += nums[i];
                    low.insert(nums[i]);
                } else {
                    sum2 += nums[i];
                    high.insert(nums[i]);
                }

                // Rebalance the sets again
                while(low.size() < (x+1)/2) {
                    sum1 += *high.begin();
                    sum2 -= *high.begin();
                    low.insert(*high.begin());
                    high.erase(high.begin());
                }
                while(low.size() > (x+1)/2) {
                    sum1 -= *low.rbegin();
                    sum2 += *low.rbegin();
                    high.insert(*low.rbegin());
                    low.erase(--low.end());
                }

                // Store the cost for current window
                median.push_back(-(sum1 - 1LL * low.size() * (*low.rbegin()) + 1LL * high.size() * (*low.rbegin()) - sum2));
            }
        }

        // Step 3: Initialize dp[0][0] to 0
        dp[0][0] = 0;
        for(int i = 0; i < n; i++) {
            dp[i][0] = 0; // Cost of selecting 0 segments is 0
        }

        // Step 4: Fill the dp table
        for(int i = x - 1; i < n; i++) { // Start from index x-1 since we need full window to select
            for(int j = 1; j <= k; j++) {
                if(i == x - 1) {
                    // First segment, directly take its cost
                    if(j == 1) {
                        dp[i][j] = median[0];
                    }
                } else {
                    // Either do not take segment ending at i, or take it and add cost of segment [i-x+1...i]
                    dp[i][j] = min(dp[i-1][j], dp[i-x][j-1] + median[i - (x - 1)]);
                }
            }
        }

        // Final result: min cost to choose k non-overlapping segments of size x
        return dp[n-1][k];
    }
};
