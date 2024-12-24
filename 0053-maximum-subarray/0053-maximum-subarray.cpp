class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int sum=nums[0], maxi =nums[0];

        for(int i=1; i<nums.size(); i++){
            sum =  sum + nums[i];
            if(sum < nums[i]){
                sum = nums[i];
            }
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};