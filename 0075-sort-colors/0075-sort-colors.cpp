class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int s=0,e=n-1,k=0;
        while(k <= e){
            if(nums[k] == 1)
                k++;
            else if(nums[k] == 0)
                swap(nums[s++],nums[k++]);
            else
                swap(nums[e--],nums[k]);
        }
    }
};