class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
       
        int s=0, e=n-1;
        while(s < e){
            int m = s+(e-s)/2;

            if(m%2 == 1){
                m--;
            }
            if(nums[m] == nums[m+1]){
                s = m+2;
            }
            else{
                e = m;
            }
            
        }
        return nums[s];
    }
};