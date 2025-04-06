class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long>median;
        {
            multiset<int>low, high;
            long long sum1 = 0, sum2=0;

            for(int i=0;i<x; i++){
                sum1 += nums[i];
                low.insert(nums[i]);
            }

            while(low.size() > (x+1)/2 ){
                auto it = low.rbegin();
                sum1 -= *it;
                sum2 += *it;
                high.insert(*it);
                low.erase(prev(low.end()));
            }

            median.push_back( ( 1LL* low.size() *  (*low.rbegin()) - sum1 ) + ( sum2 - 1LL*high.size()* (*low.rbegin())  )   );
             //median.push_back(-(sum1 - 1LL * low.size() * (*low.rbegin()) + 1LL * high.size() * (*low.rbegin()) - sum2));
            for(int i=x; i<n; i++){
                // 1. remove nums[i-x]
                int rem = nums[i-x];
                if(low.size() && rem <= *low.rbegin() ){
                    low.erase( low.find(rem) );
                    sum1 -= rem;
                }else{
                    high.erase( high.find(rem) );
                    sum2 -= rem;
                }

                // 2. add nums[i]
                int add = nums[i];
                if( low.size() && add <= *low.rbegin()  ){
                    low.insert(add );
                    sum1 += add;
                }else{
                    high.insert(add );
                    sum2 += add;
                }

                //3. readjust low and high multisets

                while(low.size() > (x+1)/2 ){
                    high.insert( *low.rbegin() );
                    sum2 += *low.rbegin();
                    sum1 -= *low.rbegin();
                    low.erase( prev(low.end()) );
                }

                while(low.size() < (x+1)/2 ){
                    low.insert( *high.begin() );
                    sum1 += *high.begin();
                    sum2 -= *high.begin();
                    high.erase(high.begin());
                }

            median.push_back( ( 1LL* low.size() *  (*low.rbegin()) - sum1 ) + ( sum2 - 1LL*high.size()* (*low.rbegin())  )   );
            //median.push_back(-(sum1 - 1LL * low.size() * (*low.rbegin()) + 1LL * high.size() * (*low.rbegin()) - sum2));
            }
        }

         // Step 3: Initialize dp[0][0] to 0
        vector<vector<long long>> dp(n, vector<long long>(k+1, 1e18));
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

        
        return dp[n-1][k];
    }
};