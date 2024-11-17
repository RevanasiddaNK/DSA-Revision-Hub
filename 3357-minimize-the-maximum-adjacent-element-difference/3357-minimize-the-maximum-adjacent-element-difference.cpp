class Solution {
public:


 bool isValidMinDiff(vector<int>nums, int n, int maxDiff) {

        int min_element = INT_MAX;
        int max_element = INT_MIN;

        for(int i=0;i<n; i++){
           if( nums[i] != -1 &&  (  i && nums[i-1] == -1  ||  i != n-1 && nums[i+1] == -1    )  ){
                min_element = min(min_element, nums[i]);
                max_element= max(max_element, nums[i]);
            }
        }
    

        int minValue = min_element + maxDiff;  // The lower bound value - X
        int maxValue = max_element - maxDiff;  // The upper bound value - Y


        for(int i=0; i<n; i++){
            if(nums[i] == -1){
              if( ( i==0 || abs(nums[i-1] - minValue) <= maxDiff ) && ( i == n-1 || nums[i+1] == -1 || abs(nums[i+1] - minValue) <= maxDiff )  ){
                    nums[i] = minValue;
                }
                else{
                    nums[i] = maxValue;
                }
            }
    
        }

        // After replacing all -1 values, check if the difference between adjacent elements is within `maxDiff`
        for (int i = 0; i < nums.size()-1; i++) {
            if (abs(nums[i] - nums[i+1]) > maxDiff) {  // If any difference exceeds `maxDiff`, return false
                return false;
            }
        }

        // If no differences exceeded the allowed maxDiff, return true
        return true;
    }




    int minDifference(vector<int>& nums) {
        int missingCount = 0;
        int n = nums.size();
     
        for(int i:nums){
            if (i == -1) 
                missingCount++;

        }

        if(missingCount == 0){
            int maxDiff = 0;
            for(int i=1; i<n; i++){
                maxDiff = max( maxDiff, abs(nums[i] - nums[i-1]) );
            }
            return maxDiff;
        }
        else if(missingCount == n)
            return 0;

        int ans = 0;
        int s = 0;
        int e = 1000000005;
        while(s <= e){
            int m = s+(e-s)/2;
            if( isValidMinDiff(nums,n,m) ){
                e = m-1;
                ans = m;
            }
            else
                s = m+1;
        }
        return ans;
    }
};