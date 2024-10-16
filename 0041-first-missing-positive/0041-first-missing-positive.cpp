class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(n,0);

        for(int i=0; i<n; i++){
            if(nums[i] > 0 && nums[i] <= n){
                int index = nums[i] -1;
                temp[index] = 1;
            }
        }

        for(int i=0; i<n; i++){
            if(temp[i] == 0)
                return i+1;
        }
        return n+1;
    }
};