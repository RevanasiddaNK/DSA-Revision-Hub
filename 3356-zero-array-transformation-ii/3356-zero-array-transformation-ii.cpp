class Solution {
public:

    //  solved using Line Sweep Algorithm
    bool isZeroArrayValid(vector<int>& nums, vector<vector<int>>&queries, int n) {

       int n1 = nums.size();
        vector<int>sweep(n1, 0);

        for(int i=0; i <= n; i++){
            sweep[ queries[i][0] ] += queries[i][2];
            if( queries[i][1] + 1 < n1 ){
                sweep[ queries[i][1] + 1] -= queries[i][2];
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


    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        int ans = -1;
        int n = queries.size();

        // Monotonic Predicate state to K => Binary Search bcx FFFFFF  left <-T ->right TTTTTTT
        int s=0, e=n-1;
        while(s <= e){

            int m = s+(e-s)/2;

            if( isZeroArrayValid(nums, queries, m) ){
                e = m-1;
                ans = m;
            }
            else
                s = m+1;
        }

        return (ans == -1 || ans == 0)?  ans : ans+1 ;
    }
};

/*

Time Complexity: O(N*log(N))
Space Complexity: O(N)

*/