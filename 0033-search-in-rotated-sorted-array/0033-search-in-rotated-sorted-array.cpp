class Solution {
public:



    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s=0, e=n-1;

        while(s <= e){
            int m = s+(e-s)/2;
            if(nums[m] == target){
                return m;
            }
            else if( nums[s] <= nums[m] ){
                if( nums[s] <= target && nums[m] >= target ){
                     e = m-1;
                }else{
                    s = m+1;
                }
            }
             else{
                if( nums[m] <= target && nums[e] >= target ){
                    s = m+1;
                }else{
                    e=m-1;
                }
            }
        }
        return -1;
    }
};
/*
1. find out where is mid lying ?
2. if its lying in left part, check wether target lies in left part, if does consider left otherwise ignore right, same for right part too

*/