class Solution {
public:

    bool isValidSelection(vector<int>nums, int c, bool r){
        int i=c, n= nums.size();
        while(i >= 0 && i<n ){
            if(r){
                while(i < n){
                    if(nums[i] == 0)
                        i++;
                    else if(nums[i] > 0){
                        nums[i]--;
                        r = !r;
                        i--;
                        break;
                    }
                }
            }

            if(!r){
                 while(i >= 0){
                    if(nums[i] == 0)
                        i--;
                    else if(nums[i] > 0){
                        nums[i]--;
                        r = !r;
                        i++;
                        break;
                    }
                }
            }
        }

        for(i=0; i<nums.size(); i++){
            if(nums[i] != 0)
                return 0;
        }
        return 1;
    }

    int countValidSelections(vector<int>& nums) {

        int count = 0, n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                count += isValidSelection(nums, i,1);
                count += isValidSelection(nums, i,0);
            }
        }
        return count;
    }
};