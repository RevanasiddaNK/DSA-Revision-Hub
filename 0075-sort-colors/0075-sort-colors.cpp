class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k=0, z=-1, t=nums.size();

        while(k<t){
            if(nums[k] == 0){
                swap(nums[++z], nums[k++]);
            }
            else if(nums[k] == 2){
                swap(nums[--t], nums[k]);
            }
            else
                k++;
        }
    }
};