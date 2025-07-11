class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum = 0, lsum=0;
        for(int i:nums)
            rsum += i;
        int n = nums.size();

        for(int i=0; i<n; i++){
            rsum -= nums[i];
            if(rsum == lsum)
                return i;
            lsum += nums[i];
        }
        return -1;
    }
};