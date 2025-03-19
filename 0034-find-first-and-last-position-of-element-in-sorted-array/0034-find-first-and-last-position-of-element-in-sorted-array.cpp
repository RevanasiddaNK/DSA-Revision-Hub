class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = -1, r =-1, n = nums.size();
        int s=0, e=n-1;
        while(s <= e){
            int m = s+(e-s)/2;
            if(nums[m] == target){
                l = m;
                e=m-1;
            }
            else if(nums[m] < target)
                s = m+1;
            else
                e = m-1;
        }
        s=0,e=n-1;
        while(s <= e){
            int m = s+(e-s)/2;
            if(nums[m] == target){
                r = m;
                s=m+1;
            }
            else if(nums[m] < target)
                s = m+1;
            else
                e = m-1;
        }
        
        return vector<int>{l,r};
    }
};