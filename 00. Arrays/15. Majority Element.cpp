class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();
        int cd = -1,vot=0;
        for(int i=0; i<n; i++){

            if(vot == 0){
                cd = nums[i];
                vot = 1;
            }
            else{

                if(cd == nums[i])
                    vot++;
                else
                    vot--;
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == cd){
                count++;
            }
        }
        if(count > n/2)
            return cd;
        
        return -1;

    }
};