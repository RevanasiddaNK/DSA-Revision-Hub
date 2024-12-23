class Solution {
public:

    int countZeroes(vector<int>& nums) {
        int count = 0;
        for(int i : nums){
            if(i == 0)
                count++;
        }
        return count;
    }


    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int count = countZeroes(nums);

        int p = 1;
        for(int i : nums){
            if(i != 0)
                p *= i;
        }

        for(int i=0; i<n; i++){

            if(count >= 2){
                nums[i] = 0;
            }
            else if(count == 1 && nums[i] == 0 ){
                nums[i] = p;
            }
            else if(count == 1 && nums[i] != 0 ){
                nums[i] = 0;
            }
            else{
                nums[i] = p/nums[i];
            }
        }

        return nums;
    }
};

/*
    TC : O(N)
    SC : O(1)
*/