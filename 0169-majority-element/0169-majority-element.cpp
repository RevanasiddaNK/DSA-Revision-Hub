class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int v=1,c=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(c == nums[i]){
                v++;
            }else if(v == 0){
                c = nums[i];
                v=1;
            }else{
                v--;
            }
        }
        return c;
    }
};