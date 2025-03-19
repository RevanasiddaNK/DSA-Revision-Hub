class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        int n=nums.size();
        for(int i=1; i<n; i++){
            if(nums[k-1] == nums[i])
                continue;
            swap(nums[k++], nums[i++]);
        }
        return k;
    }
};