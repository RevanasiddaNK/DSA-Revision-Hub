class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i,k =0;
        for(i=n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                k=i-1;
                break;
            }
        }

        if(i==0){
            reverse(nums.begin(), nums.end());
        }
        else{
            for(int j=n-1; j>i-1;j--){
                if(nums[k] < nums[j]){
                    swap(nums[k],nums[j]);
                    sort(nums.begin()+k+1, nums.end());
                    break;
                }
            }
        }

    }
};