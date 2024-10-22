class Solution {
public:
    bool checkPossibility(vector<int>& nums) {

        if(nums.size() < 3)
            return 1;
        
        int count =0;
        for(int i=1; i<nums.size()-1; i++){
            if(nums[i-1] <= nums[i] &&  nums[i] <= nums[i+1])
                continue;
            else if(nums[i-1] > nums[i] &&  nums[i] > nums[i+1])
                return 0;
            else if(nums[i-1] <= nums[i] &&  nums[i] >= nums[i+1]){
                    if( nums[i-1] <= nums[i+1])
                        nums[i] = nums[i+1];
                    else
                        nums[i+1] = nums[i];

                    count++;
            }
            else if(nums[i-1] >= nums[i] &&  nums[i] <= nums[i+1]){
                if( nums[i-1] <= nums[i+1])
                    nums[i] = nums[i-1];
                else{

                    nums[i-1] = nums[i];
                    if(i-1 > 0)
                        i -= 2;
                }
                count++;
            }
            if(count > 1)
                return 0;
        }
        return 1;
    }
};