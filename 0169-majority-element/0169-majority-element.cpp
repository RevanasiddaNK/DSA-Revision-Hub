class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int vote = 1, cad = nums[0], n=nums.size();
        for(int i=1; i<n; i++){
            if(cad == nums[i]){
                vote++;
            }else{
                vote--;
                if(vote == 0){
                    vote = 1;
                    cad = nums[i];
                }
            }
        }
        return cad;
    }
};