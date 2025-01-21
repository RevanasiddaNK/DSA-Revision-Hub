class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int total = 0;
        int n = nums.size();
        for(int i=0;i<n; i++ ){
            int s = max(0, i-nums[i]);
            int sum = 0;
            while(s <= i){
                sum += nums[s++];
            }
            total += sum;
            sum = 0;
        }
        return total;
    }
};