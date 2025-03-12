class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cad=nums[0],vote=1;
        for(int i=1; i<nums.size(); i++){
            if(vote == 0){
                cad = nums[i];
                vote = 1;
            }
            else if(nums[i] == cad)
                vote++;
            else
                vote--;
        }
        return cad;
    }
};