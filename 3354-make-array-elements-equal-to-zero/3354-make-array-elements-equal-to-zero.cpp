class Solution {
public:

    bool isValidSelection(vector<int>nums, int c, bool r){
        int i=c, n= nums.size();
        while(i >= 0 && i<n ){
    
                while(i < n && i >= 0){
                    if(nums[i] == 0)
                        r == 1 ? i++ : i--;
                    else if(nums[i] > 0){
                        nums[i]--;
                        r == 0 ? i++ : i--;
                        r = !r;
                        break;
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

/*
    Time Complexity: O(N^2)
    Space Complexity: O(N)
*/