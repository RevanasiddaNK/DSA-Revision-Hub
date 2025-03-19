class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0,negSmall= -1, lg=INT_MIN;
        int temp = 0;
        for(int i:nums){
            lg = max(lg, i);
            temp += i;
            if(temp < 0)
                temp = 0;
            sum = max(temp, sum);
        }
        return lg < 0 ? lg : sum;
    }
};