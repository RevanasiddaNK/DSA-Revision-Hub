class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //boy more algorithm
        int cad=INT_MIN,vote=0;
        for(int i=0; i<nums.size(); i++){
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