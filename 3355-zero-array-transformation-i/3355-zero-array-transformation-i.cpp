class Solution {
public:
//  solved using Line Sweep Algorithm
    bool isZeroArray(vector<int>& nums, vector<vector<int>>&queries) {
        int n = nums.size();
        vector<int>sweep(n, 0);

        for(int i=0; i< queries.size(); i++){
            sweep[ queries[i][0] ]++;
            if( queries[i][1] + 1 < n ){
                sweep[ queries[i][1] + 1]--;
            }
        }

        int sum = 0;
        for(int i=0; i< sweep.size(); i++){
            sum += sweep[i];
            sweep[i] = sum;
        }

        for(int i=0; i< sweep.size(); i++){
            if(sweep[i] < nums[i])
                return 0;
        }
        return 1;

    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N)
*/
